#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "math.h"

class Vector{
public:
    Vector() = default;
    Vector(float x, float y, float z):x_(x),y_(y),z_(z){};
    void Rotate(float yaw, float pitch, float roll);
    Vector Rotate_nosave(float yaw, float pitch, float roll);
    float get_x(){ return x_; }
    float get_y(){ return y_; }
    float get_z(){ return z_; }
    Vector normalized();
    float norm(){return sqrt(pow(this->x_,2) + pow(this->y_,2) + pow(this->z_,2));}
    void Rotate_by_point(float x, float y, float z, float yaw, float pitch, float roll);
private:
    float x_,y_,z_;
    
};

#endif