% IN:
%   - vec = Vector Struct; assumes it has been checked for x1-x0 = 0 so as
%           to prevent a divide-by-zero error
% OUT:
%   - m = slope of vector

function m = getSlope(vec)
    m = ( (vec.y1 - vec.y2) / (vec.x1 - vec.x0) );
end