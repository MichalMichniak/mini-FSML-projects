#ifndef POINT_HPP
#define POINT_HPP

class Point{
    double point_coords[3];
public:
    Point() = default;
    Point(double x,double y,double z);
    double* get_vect(){ return this->point_coords; };
    // getters setters
    double get_x(){return this->point_coords[0];};
    double get_y(){return this->point_coords[1];};
    double get_z(){return this->point_coords[2];};
    void set_x(double x){this->point_coords[0] = x;};
    void set_y(double y){this->point_coords[1] = y;};
    void set_z(double z){this->point_coords[2] = z;};
private:

};


#endif