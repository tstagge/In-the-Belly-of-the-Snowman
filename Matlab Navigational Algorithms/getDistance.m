% IN:
%   -pt1, pt2 = any combination of 2 Beacon Location, Robot Position, and
%               Point Structs
% OUT:
%   -d = distance between the two points (float)

function d = getDistance(pt1,pt2)
    d = ( ((pt1.x - pt2.x)^2) + ((pt1.y - pt2.y)^2) )^(0.5);
end