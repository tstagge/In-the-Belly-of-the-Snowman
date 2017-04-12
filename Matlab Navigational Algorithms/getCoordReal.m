% IN:
%   - pt1 = point relative to PathGenerator's (0,0) -- the top left of the
%           map
%   - ptTemp = template for Point Struct
%   - mapSize2 = size of map matrix
%
% OUT:
%   - p = pt1, converted to the demonstration area's coordinate system

function p = getCoordReal(pt1, ptTemp, mapSize2)
    p = struct(ptTemp);
    p.x = pt1.x;
    p.y = mapSize2(1) - pt1.y;
end