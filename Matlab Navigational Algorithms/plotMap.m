function void = plotMap(map,size)
    yellow = zeros(size(1) + size(2), 2);
    red = zeros(size(1) + size(2), 2);
    black = zeros(size(1) + size(2), 2);
    green = zeros(size(1) + size(2), 2);
    
    iY = 1;
    iR = 1;
    iB = 1;
    iG = 1;
    
    for r = 1:size(1)
        for c = 1:size(2)
            switch(map(r,c))
                case -1
                    black(iB,:) = [c, -r];
                    iB = iB + 1;
                case 1
                    yellow(iY,:) = [c, -r];
                    iY = iY + 1;
                case 2
                    red(iR,:) = [c, -r];
                    iR = iR + 1;
                case 40
                    green(iG,:) = [c, -r];
                    iG = iG +1;
                otherwise
                    %Do nothing
            end
        end
    end
    plot(black(1:(iB-1),1), black(1:(iB-1),2), 'k.');
    plot(yellow(1:(iY-1),1), yellow(1:(iY-1),2), 'y.');
    plot(red(1:(iR-1),1), red(1:(iR-1),2), 'r.');
    plot(green(1:(iG-1),1), green(1:(iG-1),2), 'g.');
end