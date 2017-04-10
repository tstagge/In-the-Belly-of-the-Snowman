%IN: n = number of 'blocks' (number of nodes - 1)
%OUT: binMat = every permutation of a 2 by 2n binary matrix

function validPerms = getBinaryMatrix(n, binMatTemp)

    %numAllPerm = 2^(2*n);
    validPerms = [];
    for i = 1:2^(2*n) %numAllPerm %Generates every perm, but only stores the valid
        temp = struct(binMatTemp);
        temp.binMat = zeros(2*n,1);
        for j = 1:2*n %2*n = numCells
            numBranches = 2^(j-1);
            temp.binMat(j) = mod(floor((i-1)/numBranches),2);
        end
        if(sum(temp.binMat) == n)
            validPerms = [validPerms, temp];
        end
    end

end