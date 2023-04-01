#include <SFML/Graphics.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Vector.hpp"

#define WIDTH 800
#define HEIGHT 600
#define X_OFFSET WIDTH/2
#define Y_OFFSET HEIGHT/2


int main()
{   
    // sight_direction the direction of view of player
    // 3 dimentional vector with norm 1
    Vector sight_direction = Vector(1,0,0);
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "spinning cube");
    float z_rot = 0.00;
    float y_rot = 0.01;
    float x_rot = 0.01;
    float x_point = 150;
    float y_point = 0;
    float z_point = 0;
    float length = 100;
    float zoom = 500;
    Vector cube_vertexes[8] = {Vector(x_point,y_point + length,z_point + length),Vector(x_point,y_point + length,z_point),
    Vector(x_point,y_point,z_point + length),Vector(x_point,y_point,z_point),
    Vector(x_point + length,y_point + length,z_point + length),Vector(x_point + length,y_point + length,z_point),
    Vector(x_point + length,y_point,z_point + length),Vector(x_point + length,y_point,z_point)};

    sf::Time delay = sf::milliseconds(10);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        // update section
        for(size_t i = 0; i != 8; i++){
            cube_vertexes[i].Rotate_by_point(x_point,y_point,z_point,x_rot,y_rot,z_rot);
        }
        // draw section
        for(size_t i = 0; i != 8; i++){
            for(size_t j = i+1; j < 8; j++){
                Vector v1 = cube_vertexes[i].Rotate_nosave(0.785375,-0.785375,0.785375);
                Vector v2 = cube_vertexes[j].Rotate_nosave(0.785375,-0.785375,0.785375);
                sf::Vertex line_vect[] = {
                    sf::Vertex(sf::Vector2f((zoom*v1.get_x()/(v1.get_z()+zoom)) + X_OFFSET, (zoom*v1.get_y()/(v1.get_z()+zoom)) + Y_OFFSET)),
                    sf::Vertex(sf::Vector2f((zoom*v2.get_x()/(v2.get_z()+zoom)) + X_OFFSET, (zoom*v2.get_y()/(v2.get_z()+zoom)) + Y_OFFSET))
                };
                line_vect[0].color = sf::Color((i*32)%256,(j*32)%256,255);
                line_vect[1].color = sf::Color((i*32)%256,(j*32)%256,255);
                window.draw(line_vect,2,sf::Lines);
            }
        }
        window.display();
        sf::sleep(delay);
    }

    return 0;
}