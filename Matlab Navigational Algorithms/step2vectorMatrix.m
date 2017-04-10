% IN:
%     -currLoc = Robot Position Struct
%     -currDest = Beacon Location Struct
%     -stepPerms = list of Path Structs w/ binMat and stepMat
%     -ptTemp = template for a Point Struct
%     -vecTemp = template for Vector Struct
% OUT:
%     -paths = list of Path Strcuts w/ binMat, stepMat, and vectorList
% NOTES:
%     -At the moment, somehow printing a logical?

function paths = step2vectorMatrix(currLoc, currDest, n, stepPerms, ptTemp, vecTemp)
    paths = stepPerms;
    
    deltaXtot = currDest.x - currLoc.x;
    deltaYtot = currDest.y - currLoc.y;
    deltaXn = floor(deltaXtot/n);
    deltaYn = floor(deltaYtot/n);
    %deltaXf = n - (deltaXn * (n-1));
    %deltaYf = n - (deltaYn * (n-1));
    
    % MAKE EMPTY NODE ARRAY
    nodes = [];
    nodesCol = [];
    for iNy = 1:(n+1)
        nodesCol = [nodesCol; struct(ptTemp)];
    end
    for iNx = 1:(n+1)
        nodes = [nodes, nodesCol];
    end
    
    % POPULATE NODE ARRAY
    for iNx = 1:(n+1)
        for iNy = 1:(n+1)
            if(iNx <= n)
                nodes(iNx,iNy).x = currLoc.x + (deltaXn * (iNx-1));
            else(iNx > n)
                nodes(iNx,iNy).x = currDest.x;
            end
            
            if(iNy <= n)
                nodes(iNx,iNy).y = currLoc.y + (deltaYn * (iNy-1));
            else(iNy > n)
                nodes(iNx,iNy).y = currDest.y;
            end
        end
    end
    
    % PLOT NODES
    plotNodes(nodes);
    
end
