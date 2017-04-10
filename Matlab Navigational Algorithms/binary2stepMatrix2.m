%Attempt to change so as simply to update the input; got some weird index
%out of bounds error though

function paths = binary2stepMatrix2(paths, pathTemp)
    numPerms = length(paths); %Total number of unit permutation matrices (same as number of path matrices)
    numCells = length(paths(1).binMat);
    paths = [];
    for p = 1:numPerms
        %paths = [paths, struct(pathTemp)];
        %paths(p).binMat = paths(p).binMat;
        
        %Figure out needed size of pathMat array
        i = 2;
        numSwitch = 0;
        while(i <= numCells)
            if(not(paths(p).binMat(i) == paths(p).binMat(i-1)))
                numSwitch = numSwitch + 1;
            end
            i = i + 1;
        end
        %fprintf('NumSwitch in unitPerm %d: %d\n',p,numSwitch);
        paths(p).stepMat = zeros(2,numSwitch+1);
        
        %Sum and assign values to pathMat
        currentSum = 0;
        lastSwitchI = 1;
        numMoves = 1;
        i = 2;
        while(i <= numCells)
            if( not(paths(p).binMat(i) == paths(p).binMat(i-1)) )%| i == numCells)
                currentSum = i - lastSwitchI;
                if(paths(p).binMat(i-1) == 1)
                    paths(p).stepMat(1,numMoves) = currentSum;
                else
                    paths(p).stepMat(2,numMoves) = currentSum;
                end
                numMoves = numMoves + 1;
                lastSwitchI = i;
            end
            i = i + 1;
        end
        currentSum = i - lastSwitchI;
        if(paths(p).binMat(i-1) == 1)
            paths(p).stepMat(1,numMoves) = currentSum;
        else
            paths(p).stepMat(2,numMoves) = currentSum;
        end
        %fprintf('Exiting loop. I = %d, lastSwitchI = %d\n', i, lastSwitchI);
    end
end