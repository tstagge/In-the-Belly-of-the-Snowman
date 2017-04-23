% IN:
%   - pt1 = point relative to PathGenerator's (0,0) -- the top left of the
%           map
%   - o = map origin relative to demonstration area's bottom left corner
%   - ptTemp = template for Point Struct
%   - mapSize2 = size of map matrix
%
% OUT:
%   - p = pt1, converted to the map's coordinate system

function p = getCoordReal(pt1, o, ptTemp, mapSize2)
    p = struct(ptTemp);
    p.x = pt1.x;
    p.y = mapSize2(1) - pt1.y;
    
    p.y = p.y - o.y;
    p.x = p.x - o.x;
end