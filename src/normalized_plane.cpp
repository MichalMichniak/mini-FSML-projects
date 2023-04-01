#include <SFML/Graphics.hpp>
#include "Vector.hpp"
#define WIDTH 800
#define HEIGHT 600
#define X_OFFSET WIDTH/2
#define Y_OFFSET HEIGHT/2
int main()
{
    // plane vector
    // 3 dimentional vector with norm 1
    float z_rot = 0.00;
    float y_rot = 0.00;
    float x_rot = 0.01;
    float x_point = 100;
    float y_point = 100;
    float z_point = 100;
    int val = 10;
    Vector sight_direction = Vector(x_point + 100,y_point + 0,z_point + 0);
    Vector sight_direction1 = Vector(x_point + 100,y_point +val,z_point +val);
    Vector sight_direction2 = Vector(x_point + 100,y_point -val,z_point +val);
    Vector sight_direction3 = Vector(x_point + 100,y_point -val,z_point-val);
    Vector sight_direction4 = Vector(x_point + 100,y_point +val,z_point-val);
    Vector begin = Vector(x_point,y_point,z_point);
    Vector Ox = Vector(100,0,0);
    Vector Oy = Vector(0,100,0);
    Vector Oz = Vector(0,0,100);
    std::vector<sf::CircleShape> circ;
    Vector disp;
    Vector begin_inv = begin.Rotate_nosave(0.785375,-0.785375,0.785375);
    sf::Vertex line_vect[] = {
        sf::Vertex(sf::Vector2f(begin_inv.get_x() + X_OFFSET,begin_inv.get_y() + Y_OFFSET)),
        sf::Vertex(sf::Vector2f(1,0))
    };

    Vector Ox_vect = Ox.Rotate_nosave(0.785375,-0.785375,0.785375);
    sf::Vertex Ox_sf_vect[] = {
        sf::Vertex(sf::Vector2f(0 + X_OFFSET,0 + Y_OFFSET)),
        sf::Vertex(sf::Vector2(Ox_vect.get_x() + X_OFFSET,Ox_vect.get_y() + Y_OFFSET))
    };

    Vector Oy_vect = Oy.Rotate_nosave(0.785375,-0.785375,0.785375);
    sf::Vertex Oy_sf_vect[] = {
        sf::Vertex(sf::Vector2f(0 + X_OFFSET,0 + Y_OFFSET)),
        sf::Vertex(sf::Vector2f(Oy_vect.get_x() + X_OFFSET,Oy_vect.get_y() + Y_OFFSET))
    };

    Vector Oz_vect = Oz.Rotate_nosave(0.785375,-0.785375,0.785375);
    sf::Vertex Oz_sf_vect[] = {
        sf::Vertex(sf::Vector2f(0 + X_OFFSET,0 + Y_OFFSET)),
        sf::Vertex(sf::Vector2f(Oz_vect.get_x() + X_OFFSET,Oz_vect.get_y() + Y_OFFSET))
    };
    Oz_sf_vect[0].color = sf::Color(255,0,0,255);
    Oy_sf_vect[0].color = sf::Color(0,255,0,255);
    Ox_sf_vect[0].color = sf::Color(0,0,255,255);
    Oz_sf_vect[1].color = sf::Color(255,0,0,255);
    Oy_sf_vect[1].color = sf::Color(0,255,0,255);
    Ox_sf_vect[1].color = sf::Color(0,0,255,255);

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "vector rotation test");
    sf::Time delay = sf::milliseconds(10);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    x_rot = x_rot - 0.001;
                }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    x_rot = x_rot + 0.001;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                    y_rot = y_rot - 0.001;
                }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                    y_rot = y_rot + 0.001;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                    z_rot = z_rot - 0.001;

                }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
                    z_rot = z_rot + 0.001;
                }
            }
        }
        window.clear(sf::Color::Black);
        // update section
        

        sight_direction.Rotate_by_point(x_point,y_point,z_point,x_rot,y_rot,z_rot);
        sight_direction1.Rotate_by_point(x_point,y_point,z_point,x_rot,y_rot,z_rot);
        sight_direction2.Rotate_by_point(x_point,y_point,z_point,x_rot,y_rot,z_rot);
        sight_direction3.Rotate_by_point(x_point,y_point,z_point,x_rot,y_rot,z_rot);
        sight_direction4.Rotate_by_point(x_point,y_point,z_point,x_rot,y_rot,z_rot);
        disp = sight_direction.Rotate_nosave(0.785375,-0.785375,0.785375);
        line_vect[1] = sf::Vertex(sf::Vector2f(disp.get_x() + X_OFFSET,disp.get_y() + Y_OFFSET));
        sf::CircleShape circle = sf::CircleShape(1);
        circle.setPosition(disp.get_x() + X_OFFSET,disp.get_y() + Y_OFFSET);
        circle.setFillColor(sf::Color(0xf47fffFF));
        circ.push_back(circle);
        if(circ.size() > 1000){
            circ.erase(circ.begin());
        }
        // rotating square 
        Vector sight_direction1_sf = sight_direction1.Rotate_nosave(0.785375,-0.785375,0.785375);
        Vector sight_direction2_sf = sight_direction2.Rotate_nosave(0.785375,-0.785375,0.785375);
        Vector sight_direction3_sf = sight_direction3.Rotate_nosave(0.785375,-0.785375,0.785375);
        Vector sight_direction4_sf = sight_direction4.Rotate_nosave(0.785375,-0.785375,0.785375);
        sf::Vertex sight_direction1_sf_vect[] = {
            sf::Vertex(sf::Vector2f(sight_direction4_sf.get_x() + X_OFFSET,sight_direction4_sf.get_y() + Y_OFFSET)),
            sf::Vertex(sf::Vector2f(sight_direction1_sf.get_x() + X_OFFSET,sight_direction1_sf.get_y() + Y_OFFSET))
        };

        
        sf::Vertex sight_direction2_sf_vect[] = {
            sf::Vertex(sf::Vector2f(sight_direction1_sf.get_x() + X_OFFSET,sight_direction1_sf.get_y() + Y_OFFSET)),
            sf::Vertex(sf::Vector2f(sight_direction2_sf.get_x() + X_OFFSET,sight_direction2_sf.get_y() + Y_OFFSET))
        };

        
        sf::Vertex sight_direction3_sf_vect[] = {
            sf::Vertex(sf::Vector2f(sight_direction2_sf.get_x() + X_OFFSET,sight_direction2_sf.get_y() + Y_OFFSET)),
            sf::Vertex(sf::Vector2f(sight_direction3_sf.get_x() + X_OFFSET,sight_direction3_sf.get_y() + Y_OFFSET))
        };

        sf::Vertex sight_direction4_sf_vect[] = {
            sf::Vertex(sf::Vector2f(sight_direction3_sf.get_x() + X_OFFSET,sight_direction3_sf.get_y() + Y_OFFSET)),
            sf::Vertex(sf::Vector2f(sight_direction4_sf.get_x() + X_OFFSET,sight_direction4_sf.get_y() + Y_OFFSET))
        };

        // draw section

        window.draw(line_vect,2,sf::Lines);
        window.draw(Ox_sf_vect,2,sf::Lines);
        window.draw(Oy_sf_vect,2,sf::Lines);
        window.draw(Oz_sf_vect,2,sf::Lines);

        window.draw(sight_direction1_sf_vect,2,sf::Lines);
        window.draw(sight_direction2_sf_vect,2,sf::Lines);
        window.draw(sight_direction3_sf_vect,2,sf::Lines);
        window.draw(sight_direction4_sf_vect,2,sf::Lines);


        for(auto it = circ.begin(); it != circ.end(); it++){
            window.draw(*it);
        }
        window.display();
        sf::sleep(delay);
    }

    return 0;
}