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
    
    %Fill in some up-to-now uncalculated values
    numVec = length(opt.vectorList);
    for v = 1:numVec
        opt.vectorList(v).angle = getAngle(opt.vectorList(v));
        opt.vectorList(v).magnitude = getMagnitude(opt.vectorList(v));
    end
end