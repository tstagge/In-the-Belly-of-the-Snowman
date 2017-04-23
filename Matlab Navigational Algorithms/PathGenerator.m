% ENGR 142: Project 3
% Team 57
%   Jillian Hestle, Emily Schott, Tyler Stagge, Nicholas Vilbrandt

% STATIC PATH GENERATING NAVIGATIONAL ALGORITHM [PathGenerator.m]

%% CLEAR COMMANDS et al.
clc; clear;
hold on;
tic;

%% CONSTANTS
NODE_GRID_BLOCK_NUM = 3;
TOL_CONTIGUITY = 5;   %Contiguity tolerance for finding beacons in mode 0 (test)
TOL_CONTIGUITY_ORIGIN = 2; %Contiguity tolerance for finding origin in mode 1 (real)
ROBOT_SIZE = [[7,18], 15]; % [lfront, lrear,width] (cm); wheel separation is 14.5cm
SCORE_MATRIX = [-1, 1000000;
                0, 1;
                1, 10;
                2, 100;
                40, 0];

% Will-be-inputs
START_LOC_X = 85;%340;%30;%340;%30;%340;
START_LOC_Y = 245;%30;%245;%30;%245;%30;
START_LOC_THETA = 90; %degrees
ORIGIN_X = 0;
ORIGIN_Y = 0;
NAVIGATION_MODE = 0; % 0=Test, 1="Real"
MAP_FILENAME = 'satmap5.txt';
OUTPUT_FILENAME = 'satmap5_mrdC4.c';

%% STRUCT TEMPLATES

% Robot Position Struct
f1 = 'x'; v1 = 0;
f2 = 'y'; v2 = 0;
f3 = 'theta'; v3 = 0; %Don't think this is currently used anywhere
positionTemplate = struct(f1,v1,f2,v2,f3,v3);

% Simple Coordinate Point Struct
pointTemplate = struct(f1,v1,f2,v2);

% Beacon Location Struct
f4 = 'priority'; v4 = -1;
f11 = 'distance'; v11 = 0;
beaconTemplate = struct(f1,v1,f2,v2,f4,v4,f11,v11);

% Vector Struct
f5 = 'x0'; v5 = 0;
f6 = 'x1'; v6 = 0;
f7 = 'y0'; v7 = 0;
f8 = 'y1'; v8 = 0;
f9 = 'magnitude'; v9 = 0;
f10 = 'angle'; v10 = 0;
f16 = 'slope'; v16 = 0;
vectorTemplate = struct(f5,v5,f6,v6,f7,v7,f8,v8,f9,v9,f10,v10,f16,v16);

% Path Struct
f12 = 'binMat'; v12 = []; %Was once its own struct
f13 = 'stepMat'; v13 = [[];[]]; %1st row is x movements; 2nd row is y movements
f14 = 'vectorList'; v14 = [];
f17 = 'numTurns'; v17 = 0;
f18 = 'cellTypes'; v18 = [];
f15 = 'score'; v15 = 0;
f19 = 'valid'; v19 = true;
f20 = 'turnAngles'; v20 = []; %Positive => Left, Negative => Right
pathTemplate = struct(f12,v12,f13,v13,f14,v14,f17,v17,f15,v15,f19,v19,f20,v20);

% Integrated Path Struct
intPathTemplate = struct(f14,v14,f17,v17,f15,v15,f20,v20);

%% INPUTS

mapFileName = MAP_FILENAME;
outputFileName = OUTPUT_FILENAME;

startLocation = struct(positionTemplate);
startLocation.x = START_LOC_X;
startLocation.y = START_LOC_Y;
startLocation.theta = START_LOC_THETA;

mapOrigin = struct(pointTemplate);
mapOrigin.x = ORIGIN_X;
mapOrigin.y = ORIGIN_Y;

navMode = NAVIGATION_MODE;

%mapFileName = input('Input name of provided satellite map file: ','s');
%outputFileName = input('Input name of MRD-Code output file: ','s');
% startLocation.x = input('Starting location (x): ');
% startLocation.y = input('Starting location (y): ');
% startLocation.theta = input('Starting location (theta): ');


%% IMPORT SATELLITE MAP
%  - The text file (that will be provided to us) with the 365 x 275 pixel
%    matrix (Or a test map that hasbeen run through bmp2satTxt.m)

mapRaw = load(mapFileName);
mapRawSize = size(mapRaw);

%% PROCESS SATELLITE MAP
plotMap(mapRaw, mapRawSize);
mapProcessed = mapRaw; %Copy

if(navMode == 0) %Testing mode -- our maps
    %BEACON LOCATIONS----------------------------------------------------------
    %  Note: might want to split up locateBeacons such that all40s is returned
    %  to the script and all40s can be changed to 0s, leaving only the 41 (if
    %  that is so desired later in the program development)
    beaconLocations = locateBeacons(mapRaw, mapRawSize, TOL_CONTIGUITY, beaconTemplate); %List of pseudo-unknown size
    numBeacons = length(beaconLocations);
    beaconPlotX = [];
    beaconPlotY = [];
    for b = 1:numBeacons
        mapProcessed(beaconLocations(b).y,beaconLocations(b).x) = 41;
        beaconLocations(b).distance = getDistance(beaconLocations(b), startLocation);
        beaconPlotX = [beaconPlotX, beaconLocations(b).x];
        beaconPlotY = [beaconPlotY, -beaconLocations(b).y];
    end

    %BEACON PRIORITY-----------------------------------------------------------
    %  Note: it is believed they will be giving us a specific order, but for
    %  now we are going to do it based on distance
    orderOfPriority = zeros(1,numBeacons);
    minDist = inf;
    minDistI = 0;
    prior = 1;
    for b1 = 1:1:numBeacons %Identify closest to starting location
        if(beaconLocations(b1).distance < minDist)
            minDist = beaconLocations(b1).distance;
            minDistI = b1;
        end
        %fprintf('MinDist = %d\n', minDist);
    end
    beaconLocations(minDistI).priority = prior;
    orderOfPriority(prior) = minDistI;
    prior = prior + 1;

    %Identify subsequent beacons
    latestPriorI = minDistI;
    nextPriorI = -1;
    while(prior <= numBeacons)
        minDistFromLast = 100000;
        for b1 = 1:numBeacons
            distFromLast = getDistance(beaconLocations(latestPriorI), beaconLocations(b1));
            if(beaconLocations(b1).priority == -1) %Unassigned priority
                if(distFromLast < minDistFromLast)
                    minDistFromLast = distFromLast;
                    nextPriorI = b1;
                end
            end
        end
        beaconLocations(nextPriorI).priority = prior;
        orderOfPriority(prior) = nextPriorI;
        %fprintf('Setting priority to %d\n', prior);
        prior = prior + 1;
        latestPriorI = nextPriorI;
    end
else %if(navMode == 1) %"Real" Mode -- their maps
    beaconLocations = locateBeaconsReal(mapRaw, mapRawSize, beaconTemplate); %List of pseudo-unknown size
    numBeacons = length(beaconLocations);
    beaconPlotX = [];
    beaconPlotY = [];
    orderOfPriority = zeros(1,numBeacons);
    for b = 1:numBeacons
        beaconPlotX = [beaconPlotX, beaconLocations(b).x];
        beaconPlotY = [beaconPlotY, -beaconLocations(b).y];
        orderOfPriority(beaconLocations(b).priority) = b;
    end
    mapOrigin = locateMapOriginReal(mapRaw, mapRawSize, TOL_CONTIGUITY_ORIGIN, pointTemplate);
end

%% PATH GENERATION (Version 1: all 90 degree turns)

currentLoc = startLocation; %These will eventually be in loops
numBlocks = NODE_GRID_BLOCK_NUM; %Currently 3
totalPathsCalculated = 0;
optPaths = [];

for beacon = 1:(numBeacons + 1)
    if(beacon <= numBeacons)
        currentDest = beaconLocations(orderOfPriority(beacon));
    else
        currentDest = startLocation;
    end
    %Note: unitPermutations, stepPermutations, and pathPermutations are all
    % currently lists of Path Structs, each with the content of the previous,
    % plus a bit more
    unitPermutations = getBinaryMatrix(numBlocks, pathTemplate);
    stepPermutations = binary2stepMatrix(unitPermutations, pathTemplate);
    pathPermutations = step2vectorMatrix(currentLoc, currentDest, numBlocks, stepPermutations, pointTemplate, vectorTemplate);
    %scoredPathPermutations = scorePaths(mapProcessed, SCORE_MATRIX, pathPermutations);
    scoredPathPermutations = scorePaths2(mapProcessed, SCORE_MATRIX, ROBOT_SIZE, pathPermutations);
    optPath = findOptPath(scoredPathPermutations, pathTemplate);
    if(optPath.valid == false)
        fprintf('ERROR: No valid path found to beacon %d', beacon);
    end
    plotPath(optPath);
    
    if(beacon <= numBeacons)
        currentLoc = beaconLocations(orderOfPriority(beacon));
    else
        currentLoc = startLocation; %As of right now, this shouldn't actually be used, but it will be assigned
    end
    
    %Counters/Data Trackers
    totalPathsCalculated = totalPathsCalculated + length(pathPermutations);
    optPaths = [optPaths, optPath];
end

%% MRD-CODE OUTPUT
%combinedOptPath = outputMRD(optPaths,outputFileName,vectorTemplate,intPathTemplate,pointTemplate,mapRawSize);
combinedOptPath = outputMRDc(optPaths,mapOrigin,outputFileName,vectorTemplate,intPathTemplate,pointTemplate,mapRawSize);

%% PLOTTING

%hold on at top of program
grid on;
grid minor;
axis equal;
axis([0, mapRawSize(2), -mapRawSize(1), 0]);
title(['Path Generation of: ', mapFileName]);

plotBorder(mapRawSize);
plot(startLocation.x, -startLocation.y, 'bo');
plot(beaconPlotX, beaconPlotY, 'ro'); %Average beacon locations
hold off;

%% REPORT
fprintf('Blocks (n) = %d\n', numBlocks);
fprintf('Total paths calculated = %d\n', totalPathsCalculated);
fprintf('Paths calculated per movement = %d\n', length(pathPermutations));
fprintf('Lowest path score = %d\n', optPaths.score);
fprintf('Runtime (s) = %f\n', toc);

