#include "Point.hpp"
class Line{
    Point points[2];
public:
    Line(Point& point_1, Point& point_2){
        this->points[0] = point_1; 
        this->points[0] = point_2;
        };
    Point* get_vect(){ return this->points; };
    // getters setters
    Point get_x(){return this->points[0];};
    Point get_y(){return this->points[1];};
    void set_x(Point x){this->points[0] = x;};
    void set_y(Point y){this->points[1] = y;};
private:

};