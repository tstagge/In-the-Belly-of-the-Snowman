function opt = findOptPath(allScoredPaths)
    iOpt = 0;
    lowestScore = inf;
    numPaths = length(allScoredPaths);
    for p = 1:numPaths
        if(allScoredPaths(p).score < lowestScore)
            lowestScore = allScoredPaths(p).score;
            iOpt = p;
        end
    end
    opt = allScoredPaths(iOpt);
end