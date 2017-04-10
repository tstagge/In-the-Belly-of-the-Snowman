% IN:
%     map = the raw map matrix
%     size = the 2x1 matrix of the height and width of the map matrix
%     tolCont = desired tolerance (in terms of pixels) for two cells to be
%               considered contiguous
%     ptTemp = empty struct template for a point struct
% OUT:
%     centers = the rounded! average coordinates for each contiguous group
%               of cells (in a list of point structs)

function centers = locateBeacons(map, size, tolCont, bcnTemp)
    %----LOCATE ALL 40s IN MAP---------------------------------------------
    all40s = [];
    %all40s = repmat(struct(bcnTemp),1,1000);
    for i = 1:1:size(1)
        for j = 1:1:size(2)
            if(map(i,j) == 40)
                pt = struct(bcnTemp);
                pt.y = i; %Rows are y-axis
                pt.x = j; %Columns are x-axis
                all40s = [all40s pt];
            end
        end
    end
    num40s = length(all40s);
    %fprintf('Num 40s: %d\n', num40s);
    
    %----FIND ALL CONTIGUOUS BLOCKS----------------------------------------
    contiguousGroups = [all40s(1)];
    contNumGroups = 1; %Number of rows in continguousGroups
    contGroupSizes = [1]; %Number of actual elements in each row
    contGroupSizeMax = 1;
    
    for i = 2:1:num40s
        foundContiguous = false; %Fresh for every new element of all40s
        group = 1;
        while( (foundContiguous == false) & (group <= contNumGroups) )
            element = 1;
            while( (foundContiguous == false) & (element <= contGroupSizes(group)) )
                contiguousX = (abs(contiguousGroups(group,element).x - all40s(i).x) <= tolCont); %1);
                contiguousY = (abs(contiguousGroups(group,element).y - all40s(i).y) <= tolCont); %1);
                
                if(contiguousX & contiguousY) %Contiguous; need to add element
                    %fprintf('Found contiguous.');
                    foundContiguous = true;
                    %Add [all40s(i)] to the end of [group] row of the
                    % [contiguousGroups] matrix
                    
                    if(contGroupSizes(group) >= contGroupSizeMax) %Have to extend every row
                        %fprintf('Adding new column\n');
                        emptyAppendArray = [];
                        for j = 1:contNumGroups %Creates a column array of the proper size to tack on
                            emptyAppendArray = [emptyAppendArray; struct(bcnTemp)];
                        end
                        contiguousGroups = [contiguousGroups, emptyAppendArray];
                        contGroupSizeMax = contGroupSizeMax + 1;
                    end
                    %fprintf('\n');
                    contiguousGroups(group,(contGroupSizes(group) + 1)) = all40s(i);
                    contGroupSizes(group) = contGroupSizes(group) + 1;
                end
                
                element = element + 1;
            end
%             if(foundContiguous == false)
%                 fprintf('Didnt find contiguous in group %d\n', group);
%             end
            group = group + 1;
        end
        
        if(foundContiguous == false)%Not contiguous with any current group/row; must add a new row
            %fprintf('Didnt find contiguous. Adding new row\n');
            emptyAppendArrayRow = []; %Add new row
            for k = 1:contGroupSizeMax
                emptyAppendArrayRow = [emptyAppendArrayRow, struct(bcnTemp)];
            end
            contiguousGroups = [contiguousGroups; emptyAppendArrayRow];
            
            contiguousGroups(contNumGroups + 1, 1) = all40s(i); %Add to new row
            
            contNumGroups = contNumGroups + 1; %Added a new group (row)
            contGroupSizes = [contGroupSizes; 1]; %New group has 1 element
        end
    end
    
    %----FIND CENTERS OF EACH CONTIGUOUS BLOCK-----------------------------
    sumX = zeros(contNumGroups,1);
    sumY = zeros(contNumGroups,1);
%     avgX = zeros(contNumGroups,1);
%     avgY = zeros(contNumGroups,1);
    centers = [];
    for g = 1:contNumGroups
        for e = 1:contGroupSizes(g)
            sumX(g) = sumX(g) + contiguousGroups(g,e).x;
            sumY(g) = sumY(g) + contiguousGroups(g,e).y;
        end
%         avgX(g) = sumX(g) / contGroupSizes(g);
%         avgY(g) = sumY(g) / contGroupSizes(g);
        temp = struct(bcnTemp);
        temp.x = round(sumX(g) / contGroupSizes(g)); %avgX(g);
        temp.y = round(sumY(g) / contGroupSizes(g)); %avgY(g);
        centers = [centers, temp];
    end
end