% IN:
%   - vec = Vector Struct
%   - color = the same string one uses as an argument with plot(); can be a
%             color or indicate a dotted or dashed line is desired, etc
% VOID:
%   - Plots a line of an indicated color between the vector endpoints

function void = plotVector(vec, color)
    plot([vec.x0, vec.x1], [-vec.y0, -vec.y1], color);
end