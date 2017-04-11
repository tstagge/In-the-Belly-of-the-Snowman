% V2 Changes:
%   - Added robot buffer zone

% IN:
%   - map = processed map matrix
%   - scores = r by 2 of values expected in the map and their assosciated
%     weights to be used when scoring
% OUT:
%   - sPaths = list of Path Structs w/ binMat, stepMat, vectorList, and
%              score

function sPaths = scorePaths2(map, scores, robotSize, paths)
    sPaths = paths;
    numPaths = length(sPaths);
    numCellTypes = length(scores);
    robotHalfWidth = floor(robotSize(3)/2);
    robotFore = robotSize(1);
    robotAft = robotSize(2);
    
    for p = 1:numPaths
        numVectors = sPaths(p).numTurns + 1; %Alternatively, the length of vectorList
        sPaths(p).score = 0;
        
        sPaths(p).cellTypes = [scores(:,1), zeros(numCellTypes,1)];
        
        for v = 1:numVectors
            
            %--VERTICAL VECTORS--------------------------------------------
            if( (sPaths(p).vectorList(v).x1 - sPaths(p).vectorList(v).x0) == 0)
                delY = sPaths(p).vectorList(v).y1 - sPaths(p).vectorList(v).y0;
                stepIY = 1;
                startIY = -robotAft;
                stopIY = delY + robotFore;
                if(delY < 0)
                    stepIY = -1;
                    startIY = robotAft;
                    stopIY = delY - robotFore;
                end
                startIX = sPaths(p).vectorList(v).x0 - robotHalfWidth;
                stopIX = sPaths(p).vectorList(v).x0 + robotHalfWidth;
                %fprintf('Vertical Vector\n');
                for iY = startIY:stepIY:stopIY
                    for iX = startIX:stopIX
                        %plot(iX, -(sPaths(p).vectorList(v).y0 + iY), 'g*');
                        cell = map((sPaths(p).vectorList(v).y0 + iY), iX);
                        %fprintf('Cell = %d\n', cell');
                        for t = 1:numCellTypes
                            if(cell == sPaths(p).cellTypes(t,1))
                                sPaths(p).cellTypes(t,2) = sPaths(p).cellTypes(t,2) + 1;
                            end
                        end
                    end
                end
            else
                sPaths(p).vectorList(v).slope = getSlope(sPaths(p).vectorList(v));
                
                %-HORIZONTAL VECTORS---------------------------------------
                if(sPaths(p).vectorList(v).slope == 0)
                    delX = sPaths(p).vectorList(v).x1 - sPaths(p).vectorList(v).x0;
                    stepIX = 1;
                    startIX = -robotAft;
                    stopIX = delX + robotFore;
                    if(delX < 0)
                        stepIX = -1;
                        startIX = robotAft;
                        stopIX = delX - robotFore;
                    end
                    startIY = sPaths(p).vectorList(v).y0 - robotHalfWidth;
                    stopIY = sPaths(p).vectorList(v).y0 + robotHalfWidth;
                    %fprintf('Horizontal Vector\n');
                    for iX = startIX:stepIX:stopIX
                        for iY = startIY:stopIY
                            %plot((sPaths(p).vectorList(v).x0 + iX), -iY, 'g*');
                            cell = map(iY, (sPaths(p).vectorList(v).x0 + iX));
                            %fprintf('Cell = %d\n', cell');
                            for t = 1:numCellTypes
                                if(cell == sPaths(p).cellTypes(t,1))
                                    sPaths(p).cellTypes(t,2) = sPaths(p).cellTypes(t,2) + 1;
                                end
                            end
                        end
                    end
                    
                %-NON RECTILINEAR VECTORS----------------------------------    
                else
                    %
                end
            end
        end
        %for p...
        for t = 1:numCellTypes
            sPaths(p).score = sPaths(p).score + (scores(t,2) * sPaths(p).cellTypes(t,2));
        end
        %plotPath(sPaths(p));
    end
end