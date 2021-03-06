% IN:
%   - map = processed map matrix
%   - scores = r by 2 of values expected in the map and their assosciated
%     weights to be used when scoring
% OUT:
%   - sPaths = list of Path Structs w/ binMat, stepMat, vectorList, and
%              score

function sPaths = scorePaths(map, scores, paths)
    sPaths = paths;
    numPaths = length(sPaths);
    numCellTypes = length(scores);
    
    for p = 1:numPaths
        numVectors = sPaths(p).numTurns + 1; %Alternatively, the length of vectorList
        sPaths(p).score = 0;
        
        sPaths(p).cellTypes = [scores(:,1), zeros(numCellTypes,1)];
        
        for v = 1:numVectors
            if( (sPaths(p).vectorList(v).x1 - sPaths(p).vectorList(v).x0) == 0) %Vertical Vector
                delY = sPaths(p).vectorList(v).y1 - sPaths(p).vectorList(v).y0;
                stepIY = 1;
                if(delY < 0)
                    stepIY = -1;
                end
                %fprintf('Vertical Vector\n');
                for iY = 0:stepIY:delY
                    cell = map((sPaths(p).vectorList(v).y0 + iY), sPaths(p).vectorList(v).x0);
                    %fprintf('Cell = %d\n', cell');
                    for t = 1:numCellTypes
                        if(cell == sPaths(p).cellTypes(t,1))
                            sPaths(p).cellTypes(t,2) = sPaths(p).cellTypes(t,2) + 1;
                        end
                    end
                end
            else
                sPaths(p).vectorList(v).slope = getSlope(sPaths(p).vectorList(v));
                if(sPaths(p).vectorList(v).slope == 0) %Horizontal Vector
                    delX = sPaths(p).vectorList(v).x1 - sPaths(p).vectorList(v).x0;
                    stepIX = 1;
                    if(delX < 0)
                        stepIX = -1;
                    end
                    %fprintf('Horizontal Vector\n');
                    for iX = 0:stepIX:delX
                        cell = map(sPaths(p).vectorList(v).y0, (sPaths(p).vectorList(v).x0 + iX));
                        %fprintf('Cell = %d\n', cell');
                        for t = 1:numCellTypes
                            if(cell == sPaths(p).cellTypes(t,1))
                                sPaths(p).cellTypes(t,2) = sPaths(p).cellTypes(t,2) + 1;
                            end
                        end
                    end
                else %Non rectilinear vector!
                    %
                end
            end
        end
        %for p...
        for t = 1:numCellTypes
            sPaths(p).score = sPaths(p).score + (scores(t,2) * sPaths(p).cellTypes(t,2));
        end
    end
end