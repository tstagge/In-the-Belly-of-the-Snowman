% IN:
%     map = the raw map matrix
%     size = the 2x1 matrix of the height and width of the map matrix
%     tol = desired tolerance (in terms of pixels) for two cells to be
%           considered contiguous -- assumed the origin has no contiguous
%           elements
%     ptTemp = empty struct template for a Point struct
% OUT:
%     mapO = map origin relative to the SW corner -- VERY IMPORTANT

function mapO = locateMapOriginReal(map, size, tol, ptTemp)
    mapO = struct(ptTemp);
    mapO.x = 0;
    mapO.y = 0;
    numOs = 0;
    for i = 1:1:size(1)
        for j = 1:1:size(2)
            if(map(i,j) == 40)
                adjacent = false;
                for iI = (i - tol):1:(i + tol)
                    for jJ = (j - tol):1:(j + tol)
                        if( (map(iI,jJ) == 40) && not(iI == i) && not(jJ == j) )
                            adjacent = true;
                        end
                    end
                end
                if(adjacent == false)
                    numOs = numOs + 1;
                    mapO.x = j;
                    mapO.y = size(1) - i;
                end
            end
        end
    end
    
    switch(numOs)
        case 0
            fprintf('ERROR. No map origin found. Assuming origin to be southwest corner of map.\n');
            mapO.x = 0;
            mapO.y = size(1);
        case 1
            %Peachy
        otherwise
            fprintf('ERROR. Multiple origins found.\n');
    end
    
end