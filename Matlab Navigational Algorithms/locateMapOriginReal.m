function mapO = locateMapOriginReal(map, size, tol, ptTemp)
    mapO = struct(ptTemp);
    numOs = 0;
    for i = 1:1:size(1)
        for j = 1:1:size(2)
            potential = (map(i,j) == 40);
            adjacent = false;
            for iI = (i - tol):1:(i + tol)
                for jJ = (j - tol):1:(j + tol)
                    if( (map(iI,iJ) == 40) && not(iI == i) && not(jJ = j) )
                        adjacent = true;
                    end
                end
            end
            if(adjacent == true)
                numOs = numOs + 1;
                mapO.x = j;
                mapO.y = i;
            end
        end
    end
    
    switch(numOs)
        case 
    end
    
end