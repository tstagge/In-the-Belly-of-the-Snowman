function turnAngle = getTurnAngle(v1, v2)
    turnAngle = -999;
    theta = v2.angle - v1.angle;
    if(abs(theta) <= 180) %Note: should never actually be 180
        turnAngle = theta;
    else
        if(theta > 180)
            turnAngle = theta - 360;
        elseif(theta < -180)
            turnAngle = theta + 360;
        end
    end
end