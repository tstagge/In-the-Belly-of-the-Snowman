%Appears to somehow be printing a (0,0) somehow

function void = plotNodes(nd)
    sizeNodes = size(nd);
    numNodesX = sizeNodes(2);
    numNodesY = sizeNodes(1);
    xPlot = zeros(numNodesX * numNodesY);
    yPlot = zeros(numNodesX * numNodesY);
    iPlot = 1;
    for iNx = 1:numNodesX
        for iNy = 1:numNodesY
            xPlot(iPlot) = nd(iNx,iNy).x;
            yPlot(iPlot) = -nd(iNx,iNy).y;
            %fprintf('xPlot(%d) = %d\t', iPlot, xPlot(iPlot));
            %fprintf('yPlot(%d) = %d\n', iPlot, yPlot(iPlot));
            iPlot = iPlot + 1;
        end
    end
    %fprintf('Final length xPlot = %d\n', length(xPlot));
    %fprintf('Final iPlot = %d\n', iPlot);
    plot(xPlot, yPlot, 'k*');
end