% IN:
%   - map = processed map matrix
%   - scores = r by 2 of values expected in the map and their assosciated
%     weights to be used when scoring

function scoredPaths = scorePaths(map, scores, paths)
    scoredPaths = paths;
    numPaths = length(scoredPaths);
    for p = 1:numPaths
        numVectors = scoredPaths(p).numTurns + 1; %Alternatively, the length of vectorList
        scoredPaths(p).score = 0;
        for v = 1:numVectors
            if( (scoredPaths(p).vectorList(v).x1 - scoredPaths(p).vectorList(v).x2) == 0) %Vertical Vector
                %
            else
                scoredPaths(p).vectorList(v).slope = getSlope(scoredPaths(p).vectorList(v));
                if(scoredPaths(p).vectorList(v).slope == 0) %Horizontal Vector
                    %
                else %Non rectilinear vector!
                    %
                end
        end
    end
end