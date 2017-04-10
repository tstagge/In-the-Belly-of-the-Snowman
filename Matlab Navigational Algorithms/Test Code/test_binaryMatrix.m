%IN: n = number of 'blocks' (number of nodes - 1)
%OUT: binMat = every permutation of a 2 by 2n binary matrix

%function allBinMats = getBinaryMatrix(n, binMatTemp)
clc; clear;
% Binary Matrix Struct
f12 = 'binMat'; v12 = [];
binMatTemp = struct(f12,v12);
n = 3;

%GENERATE PERMUTATIONS
numAllPerm = 2^(2*n);
allPerms = [];
validPerms = [];

for i = 1:numAllPerm
    allPerms = [allPerms, struct(binMatTemp)];
    allPerms(i).binMat = zeros(2*n,1);
    for j = 1:2*n
        numBranches = 2^(j-1);
        %if(mod((i // numBranches),2) == 0)
        allPerms(i).binMat(j) = mod(floor((i-1)/numBranches),2);
    end
    if(sum(allPerms(i).binMat) == n)
        validPerms = [validPerms, allPerms(i)];
    end
end




%end