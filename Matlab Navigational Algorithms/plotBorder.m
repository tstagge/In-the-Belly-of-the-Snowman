% IN:
%   -size = size of map in terms of [numRows, numCols]
% VOID:
%   -Plots the lines that make up the border of the mapped region

function void = drawBorder(size)
    x = [0,size(2)];
    y = [0,-size(1)];
    
    top = [x(1), x(2); y(1), y(1)];
    bottom = [x(1), x(2); y(2), y(2)];
    left = [x(1), x(1); y(1), y(2)];
    right = [x(2), x(2); y(1), y(2)];
    
    plot(top(1,:), top(2,:), 'k');
    plot(bottom(1,:), bottom(2,:), 'k');
    plot(left(1,:), left(2,:), 'k');
    plot(right(1,:), right(2,:), 'k');
end