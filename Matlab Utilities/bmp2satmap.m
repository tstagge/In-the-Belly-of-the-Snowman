function satmap = bmp2satmap(filename)

    bitmap = imread(filename); %Reads bitmap
    bmpSize = size(bitmap);
    satmap = zeros(bmpSize(1),bmpSize(2));

    for(i = 1:1:bmpSize(1))
        for(j = 1:1:bmpSize(2))
            switch(bitmap(i,j))
                case 0 %Black in the bitmap
                    satmap(i,j) = -1;
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
end