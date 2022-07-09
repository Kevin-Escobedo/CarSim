#ifndef CAR_HPP
#define CAR_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <random>

class Car: public sf::RectangleShape
{
private:
    sf::Color color;
    double speed;
    double acceleration;
    double maxSpeed;
    double friction;
    double angle;
    bool controls[4] {false, false, false, false};
    /*
    controls[0] = forward;
    controls[1] = left;
    controls[2] = right;
    controls[3] = reverse;
    */

public:
    Car(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
    Car(const sf::Vector2u& position, const sf::Vector2u& size);
    Car(const Car& car);
    Car& operator =(const Car& car);
    void move();
    friend std::ostream& operator <<(std::ostream& os, const Car& car);

private:
    static sf::Color randomColor();
};

#endif /* CAR_HPP */
