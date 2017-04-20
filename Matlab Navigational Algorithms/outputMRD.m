% IN:
%   - oPaths = list of Path Structs representing each of the optimum paths
%              in each "operation" generated
%   - oFileName = name of file to which MRD-Code will be written
%   - vecTemp = template for Vector Struct
%   - intTemp = template for Integrated Path Struct
%   - ptTemp = template for simple coordinate Point Struct; passed to
%              getEndpointReal()
%   - mapSize = size of map [numR, numCol]; passed to getEndpointReal()
% OUT:
%   - intPath = single Integrated Path Struct

function intPath = outputMRD(oPaths,oFileName,vecTemp,intTemp,ptTemp,mapSize)
    numPaths = length(oPaths);
    intPath = struct(intTemp);
    NORTH = struct(vecTemp);
    NORTH.angle = 90;
    NORTH.magnitude = 0;
    BEACON = struct(vecTemp); %magnitude = 0;
    BEACON.magnitude = 0;
    lastNumVec = 0;
    
    %-INTEGRATE PATHS------------------------------------------------------
    for p = 1:numPaths
        numVec = length(oPaths(p).vectorList);
        oPaths(p).turnAngles = zeros(1,numVec-1);
        for v = 2:numVec
            oPaths(p).turnAngles(v-1) = getTurnAngle(oPaths(p).vectorList(v-1), oPaths(p).vectorList(v));
            %fprintf('Path %d, Vector%d to %d, Angle = %d\n',p,v-1,v,oPaths(p).turnAngles(v-1));
        end
        if(p == 1)
            intPath.turnAngles = [getTurnAngle(NORTH,oPaths(p).vectorList(1)), oPaths(p).turnAngles];
            intPath.vectorList = [NORTH, oPaths(p).vectorList];
        else
            intPath.turnAngles = [intPath.turnAngles, getTurnAngle(oPaths(p-1).vectorList(lastNumVec), oPaths(p).vectorList(1)), oPaths(p).turnAngles];
            intPath.vectorList = [intPath.vectorList, BEACON, oPaths(p).vectorList];
        end
        lastNumVec = numVec;
    end
    intPath.vectorList = [intPath.vectorList, BEACON];
    
    %-PRINT MRD-CODE TO FILE-----------------------------------------------
    totalNumVec = length(intPath.vectorList);
    totalNumTurns = length(intPath.turnAngles);
    oFile = fopen(oFileName,'w');
    
    fprintf(oFile, '*\n');
    fprintf(oFile, 'R%d\n', intPath.turnAngles(1));
    iAng = 2;
    waitOnM = false;
    iVec = 2;
    while(iVec <= totalNumVec)
        if(intPath.vectorList(iVec).magnitude == 0)
           fprintf(oFile, 'D\n'); 
        else
            if(waitOnM == false)
                fprintf(oFile, 'M%d ', intPath.vectorList(iVec).magnitude);
                expLoc = getEndpointReal(intPath.vectorList(iVec), ptTemp, mapSize);
                fprintf(oFile, '(%d %d)\n',expLoc.x,expLoc.y);
                %fprintf('iVec = %d\n', iVec);
            else
                waitOnM = false;
                iVec = iVec - 1;
            end
            if((iVec < totalNumVec)) %After the last vector, there won't be a turn
                if(not(intPath.vectorList(iVec+1).magnitude == 0))
                    %fprintf('iAng = %d\n', iAng);
                    fprintf(oFile, 'R%d\n', intPath.turnAngles(iAng));
                    iAng = iAng + 1;
                else
                    waitOnM = true;
                end
            end
        end
        iVec = iVec + 1;
    end
    fprintf(oFile, '*');
    
    fclose(oFile);
end