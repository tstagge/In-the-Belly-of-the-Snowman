% IN:
%   - v = Vector Struct
% OUT:
%   - angle = Vector's angle relative to East (CCW = +); note: these angles
%     are with respect to the actual map; all internal calculations in the
%     rest of the PathGenerator have a flipped y-axis and then flip when
%     outputting

function angle = getAngle(v)
    deltaX = v.x1 - v.x0;
    deltaY = -v.y1 + v.y0;
    theta = atand(deltaY/deltaX);
    if(deltaX >= 0)
        if(deltaY >= 0)
            angle = theta;
        else
            angle = 360 + theta;
        end
    else
        angle = 180 - theta;
    end
    %fprintf('Angle = %d\n', angle);
end