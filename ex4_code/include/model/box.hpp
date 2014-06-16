#ifndef BOX_H
#define BOX_H

#include <math.hpp>

class Box
{
private:
    vec3_type angleVec << 0,0,0;
    vec3_type positionVec << 0,0,0;
    vec3_type accelerationVec << 0,0,0;
    vec3_type speedVec.setZero << 0,0,0;
    
    vec3_type getAngleVec() {return angleVec;};
    void setAngleVec(vec3_type av) {angleVec = av};
    
    vec3_type getPositionVec() {return positionVec;};
    void setPositionVec(vec3_type pv) {positionVec = pv};
    
    vec3_type getAccelerationVec() {return accelerationVec;};
    void setAccelerationVec(vec3_type acv) {accelerationVec = acv};
    
    vec3_type getSpeedVec() {return speedVec;};
    void setSpeedVec(vec3_type sv) {speedVec = sv};
    

    
}; // Box

#endif // BOX_H
