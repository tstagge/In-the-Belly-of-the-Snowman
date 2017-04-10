% IN:
%     -currLoc = Robot Position Struct
%     -currDest = Beacon Location Struct
%     -stepPerms = list of Path Structs w/ complete stepMat's
%     -vecTemp = template for Vector Struct
% OUT:
%     -paths = list of Path Strcuts (stepPerms + each Struct has a complete
%              vectorList)

function paths = step2vectorMatrix(currLoc, currDest, stepPerms, vecTemp)