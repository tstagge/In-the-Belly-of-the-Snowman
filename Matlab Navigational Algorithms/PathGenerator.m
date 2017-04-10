% ENGR 142 Project 3
% Team 57

%% CLEAR COMMANDS et al.
clc; clear;
hold on;

%% CONSTANTS
TOL_CONTIGUITY = 5;
ROBOT_WIDTH = 15; %ish [cm]; wheel separation is 14.5cm
ROBOT_LENGTH = 25; %ish [cm]
NODE_GRID_BLOCK_NUM = 3;

% Will-be-inputs
START_LOC_X = 30;
START_LOC_Y = 245;
START_LOC_THETA = 90; %degrees
MAP_FILENAME = 'satmap1.txt';

%% STRUCT TEMPLATES

% Robot Position Struct
f1 = 'x'; v1 = 0;
f2 = 'y'; v2 = 0;
f3 = 'theta'; v3 = 0;
positionTemplate = struct(f1,v1,f2,v2,f3,v3);

% Simple Coordinate Point Struct
pointTemplate = struct(f1,v1,f2,v2);

% Beacon Location Struct
f4 = 'priority'; v4 = 0;
f11 = 'distance'; v11 = 0;
beaconTemplate = struct(f1,v1,f2,v2,f4,v4,f11,v11);

% Vector Struct
f5 = 'x0'; v5 = 0;
f6 = 'x1'; v6 = 0;
f7 = 'y0'; v7 = 0;
f8 = 'y1'; v8 = 0;
f9 = 'magnitude'; v9 = 0;
f10 = 'angle'; v10 = 0;
vectorTemplate = struct(f5,v5,f6,v6,f7,v7,f8,v8,f9,v9,f10,v10);

% Path Struct
f12 = 'binMat'; v12 = []; %Was once its own struct
f13 = 'stepMat'; v13 = [[];[]]; %1st row is x movements; 2nd row is y movements
f14 = 'vectorList'; v14 = [];
pathTemplate = struct(f12,v12,f13,v13,f14,v14);

%% INPUTS

%mapFileName = input('Input name of provided satellite map file: ','s');
mapFileName = MAP_FILENAME;
fprintf('Input name of provided satellite map file: %s\n',mapFileName);

startLocation = struct(positionTemplate);
% startLocation.x = input('Starting location (x): ');
% startLocation.y = input('Starting location (y): ');
% startLocation.theta = input('Starting location (theta): ');
startLocation.x = START_LOC_X;
startLocation.y = START_LOC_Y;
startLocation.theta = START_LOC_THETA;


%% IMPORT SATELLITE MAP
%  - The text file (that will be provided to us) with the 365 x 275 pixel
%    matrix (Or a test map that hasbeen run through bmp2satTxt.m)

mapRaw = load(mapFileName);
mapRawSize = size(mapRaw);

%% PROCESS SATELLITE MAP
mapProcessed = mapRaw; %Copy

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
minDist = 100000;
minDistI = 0;
prior = 1;
for b1 = 1:numBeacons
    if(beaconLocations(b1).distance < minDist)
        minDist = beaconLocations(b).distance;
        minDistI = b1;
    end
end
beaconLocations(minDistI).priority = prior; %This is going to take a lot of work
%prior = prior + 1;

%% PATH GENERATION (Version 1: all 90 degree turns)

currentLoc = startLocation; %These will eventually be in loops
currentDest = beaconLocations(1);
numBlocks = NODE_GRID_BLOCK_NUM; %Currently 3

%Note: unitPermutations, stepPermutations, and pathPermutations are all
% currently lists of Path Structs, each with the content of the previous,
% plus a bit more
unitPermutations = getBinaryMatrix(numBlocks, pathTemplate);
stepPermutations = binary2stepMatrix(unitPermutations, pathTemplate);
pathPermutations = step2vectorMatrix(currentLoc, currentDest, numBlocks, stepPermutations, pointTemplate, vectorTemplate);

%Score every path
%Find lowest score
%Convert to proper vectors and/or a series of movements and turns

%% PLOTTING

%hold on at top of program
grid on;
grid minor;
axis equal;
axis([0, mapRawSize(2), -mapRawSize(1), 0]);
title(['Path Generation of: ', mapFileName]);

plotBorder(mapRawSize);
plot(startLocation.x, -startLocation.y, 'b*');
plot(beaconPlotX, beaconPlotY, 'r*'); %Average beacon locations
hold off;

