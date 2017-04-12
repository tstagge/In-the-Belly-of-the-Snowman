% IN:
%   - v = Vector Struct
% OUT:
%   - mag = magnitude of said vector

function mag = getMagnitude(v)
    mag = ( ((v.x1 - v.x0)^2) + ((v.y1 - v.y0)^2) )^(0.5);
end