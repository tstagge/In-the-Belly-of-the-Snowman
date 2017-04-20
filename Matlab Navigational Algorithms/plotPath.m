function void = plotPath(path)
    numVectors = length(path.vectorList);
    for i = 1:numVectors
        plotVector(path.vectorList(i), 'r');
    end
end