function pathMatrices = binary2pathMatrix(unitPerms, pathTemp)
    numPerms = length(unitPerms); %Total number of unit permutation matrices (same as number of path matrices)
    numCells = length(unitPerms(1).binMat);
    pathMatrices = [];
    for p = 1:numPerms
        pathMatrices = [pathMatrices, struct(pathTemp)];
        i = 1;
        while(i <= numCells)
            
        end
        %pathMatrices(p).pathMat
    end
end