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
    numPaths = length(paths);
    
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
            elseif(iNx > n)
                nodes(iNx,iNy).x = currDest.x;
            end
            
            if(iNy <= n)
                nodes(iNx,iNy).y = currLoc.y + (deltaYn * (iNy-1));
            elseif(iNy > n)
                nodes(iNx,iNy).y = currDest.y;
            end
        end
    end
    
    % PLOT NODES
    plotNodes(nodes);
    
    % CONVERT STEPMAT's TO VECTORLIST
    for p = 2:2%1:numPaths
        sizeStepMat = size(paths(p).stepMat); %2 by c matrix
        numSteps = sizeStepMat(2); % c
        currXloc = 1; %In terms of the indeces of the nodes matrix
        currYloc = 1;
        for s = 1:numSteps
            currStepVec = struct(vecTemp);
            currXstep = paths(p).stepMat(1,s);
            currYstep = paths(p).stepMat(2,s);
            %fprintf('currYstep = %d\n', currYstep);
            
            currStepVec.x0 = nodes(currXloc,currYloc).x;
            currStepVec.x1 = nodes(currXloc + currXstep, currYloc + currYstep).x;
            currStepVec.y0 = nodes(currXloc, currYloc).y;
            currStepVec.y1 = nodes(currYloc + currYstep, currYloc + currYstep).y;
            %fprintf('y0 = %d\ty1=%d\n', currStepVec.y0, currStepVec.y1);
            
            currXloc = currXloc + currXstep; %Update current location
            currYloc = currYloc + currYstep;
            
            paths(p).vectorList = [paths(p).vectorList, currStepVec]; %Add step vector
            plotVector(currStepVec,'k');
        end
    end
end
