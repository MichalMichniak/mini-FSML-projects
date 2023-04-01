#include "Vector.hpp"
#include "math.h"

void linear_transform(float* v, float R[3][3]){
    float x = v[0];
    float y = v[1];
    float z = v[2];
    for(size_t i = 0; i<3; i++){
        v[i] = R[i][0] * x + R[i][1] * y +R[i][2] * z;
    }
};

void Vector::Rotate(float yaw, float pitch, float roll){
    float yaw_rot[3][3] = { {cos(yaw), -sin(yaw), 0},
                        {sin(yaw), cos(yaw) , 0},
                        {0       , 0        , 1}};
    float pitch_rot[3][3] = {{cos(pitch) , 0, sin(pitch)},
                             {0        , 1, 0},
                             {-sin(pitch), 0, cos(pitch)}};
    float roll_rot[3][3] = {{ 1, 0, 0},
                             {0, cos(roll), -sin(roll)},
                             {0, sin(roll), cos(roll)}};
    float v[3] = {this->x_,this->y_,this->z_};
    linear_transform(v,roll_rot);
    linear_transform(v,pitch_rot);
    linear_transform(v,yaw_rot);
    this->x_ = v[0];
    this->y_ = v[1];
    this->z_ = v[2];
};

Vector Vector::Rotate_nosave(float yaw, float pitch, float roll){
    float yaw_rot[3][3] = { {cos(yaw), -sin(yaw), 0},
                        {sin(yaw), cos(yaw) , 0},
                        {0       , 0        , 1}};
    float pitch_rot[3][3] = {{cos(pitch) , 0, sin(pitch)},
                             {0        , 1, 0},
                             {-sin(pitch), 0, cos(pitch)}};
    float roll_rot[3][3] = {{ 1, 0, 0},
                             {0, cos(roll), -sin(roll)},
                             {0, sin(roll), cos(roll)}};
    float v[3] = {this->x_,this->y_,this->z_};
    linear_transform(v,roll_rot);
    linear_transform(v,pitch_rot);
    linear_transform(v,yaw_rot);
    return Vector(v[0],v[1],v[2]);
}

Vector Vector::normalized(){
    float norm = this->norm();
    return Vector(this->x_/norm,this->y_/norm,this->z_/norm);
};

void Vector::Rotate_by_point(float x, float y, float z, float yaw, float pitch, float roll){
    float yaw_rot[3][3] = { {cos(yaw), -sin(yaw), 0},
                        {sin(yaw), cos(yaw) , 0},
                        {0       , 0        , 1}};
    float pitch_rot[3][3] = {{cos(pitch) , 0, sin(pitch)},
                             {0        , 1, 0},
                             {-sin(pitch), 0, cos(pitch)}};
    float roll_rot[3][3] = {{ 1, 0, 0},
                             {0, cos(roll), -sin(roll)},
                             {0, sin(roll), cos(roll)}};
    float v[3] = {this->x_ - x ,this->y_ - y,this->z_ - z};
    linear_transform(v,roll_rot);
    linear_transform(v,pitch_rot);
    linear_transform(v,yaw_rot);
    this->x_ = v[0] + x;
    this->y_ = v[1] + y;
    this->z_ = v[2] + z;
};