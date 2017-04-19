function satmap = bmp2satTxt(bmpName,fileOutName)

    bitmap = imread(bmpName); %Reads bitmap
    bmpSize = size(bitmap);
    satmap = zeros(bmpSize(1),bmpSize(2));
    
    %% Color to Data Conversion
    for(i = 1:1:bmpSize(1))
        for(j = 1:1:bmpSize(2))
            switch(bitmap(i,j))
                case 0 %Black in the bitmap
                    satmap(i,j) = -1;
                    %fprintf('Found black, mofo\n');
                case 255 %White in the bitmap
                    satmap(i,j) = 0;
                case 251 %Yellow in the bitmap
                    satmap(i,j) = 1;
                case 79 %Red in the bitmap
                    satmap(i,j) = 2;
                otherwise
                    satmap(i,j) = 40;
            end
        end
    end
    
    %% File Out
    oFile = fopen(fileOutName, 'w');
    for(i = 1:1:bmpSize(1))
        for(j = 1:1:(bmpSize(2)-1))
            fprintf(oFile, '%d, ', satmap(i,j));
        end
        fprintf(oFile, '%d\n', satmap(i,j+1));
    end
    fclose(oFile);
end