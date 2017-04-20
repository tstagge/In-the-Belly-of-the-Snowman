function opt = findOptPath(allScoredPaths, pathTemp)
    iOpt = 0;
    lowestScore = inf;
    numPaths = length(allScoredPaths);
    foundValid = false;
    for p = 1:numPaths
        if((allScoredPaths(p).valid == true)&&(allScoredPaths(p).score < lowestScore))
            lowestScore = allScoredPaths(p).score;
            iOpt = p;
            foundValid = true;
        end
    end
    
    if(foundValid == true) %There exists a valid path; set the opt to the optimum
        opt = allScoredPaths(iOpt);

        %Fill in some up-to-now uncalculated values
        numVec = length(opt.vectorList);
        for v = 1:numVec
            opt.vectorList(v).angle = getAngle(opt.vectorList(v));
            opt.vectorList(v).magnitude = getMagnitude(opt.vectorList(v));
        end
    else %There DOES NOT EXIST a valid path
        opt = struct(pathTemp);
        opt.valid = false;
    end
end