% IN:
%     map = the raw map matrix
%     size = the 2x1 matrix of the height and width of the map matrix
%     tolCont = desired tolerance (in terms of pixels) for two cells to be
%               considered contiguous
%     bcnTemp = empty struct template for a Beacon Location Struct
% OUT:
%     centers = the rounded! average coordinates for each contiguous group
%               of cells (in a list of point structs)

function centers = locateBeaconsReal(map, size, tolCont, bcnTemp)
    centers = [];
    for i = 1:1:size(1)
        for j = 1:1:size(2)
            %If an A, B, or C
            %if( not(strcmp(map(i,j), 'A')== 0) || not(strcmp(map(i,j), 'B')) || not(strcmp(map(i,j), 'C')))
            if( (map(i,j) == 65) || (map(i,j) == 66) || (map(i,j) == 67) )
                tempBcn = struct(bcnTemp);
                tempBcn.x = j;
                tempBcn.y = i;
                %tempBcn.priority = uint8(map(i,j)) - 64;
                tempBcn.priority = map(i,j) - 64;
            end
        end
    end
end