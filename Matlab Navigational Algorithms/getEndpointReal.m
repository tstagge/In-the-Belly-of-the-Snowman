% IN:
%   - v = Vector Struct, in terms of PathGenerator's coordinates
%   - ptTemp = Point Struct template
%   - mapSize1 = size of map
% OUT:
%   - pt = Point Struct of endpoint in terms of the actual demonstration
%          area's origin

function pt = getEndpointReal(v, ptTemp, mapSize1)
    vEnd = struct(ptTemp);
    vEnd.x = v.x1;
    vEnd.y = v.y1;
    pt = getCoordReal(vEnd, ptTemp,mapSize1);
end