#include "Car.hpp"

Car::Car(unsigned int x, unsigned int y, unsigned int width, unsigned int length)
:sf::RectangleShape(sf::Vector2f(width, length)), color(randomColor()), speed(0), acceleration(0.03), maxSpeed(3.0), friction(0.02), angle(0)
{
    setPosition(x, y);
    setFillColor(color);
}

Car::Car(const sf::Vector2u& position, const sf::Vector2u& size)
:Car(position.x, position.y, size.x, size.y)
{

}

Car::Car(const Car& car)
:sf::RectangleShape(car.getSize()), color(car.color), speed(car.speed), acceleration(car.acceleration), maxSpeed(car.maxSpeed), friction(car.friction), angle(car.angle), controls()
{
    for(unsigned int i = 0; i < 4; i++)
    {
        controls[i] = car.controls[i];
    }

    setPosition(car.getPosition());
    setSize(car.getSize());
    setFillColor(car.color);
}

Car& Car::operator =(const Car& car)
{
    color = car.color;
    speed = car.speed;
    acceleration = car.acceleration;
    maxSpeed = car.maxSpeed;
    friction = car.friction;
    angle = car.angle;

    for(unsigned int i = 0; i < 4; i++)
    {
        controls[i] = car.controls[i];
    }

    setFillColor(car.color);
    setPosition(car.getPosition());
    setSize(car.getSize());

    return *this;
}

void Car::move()
{

}

std::ostream& operator <<(std::ostream& os, const Car& car)
{
    os<<"Car Stats:\n";
    const sf::Vector2f position = car.getPosition();
    const sf::Vector2f size = car.getSize();

    os<<"Position: ("<<position.x<<", "<<position.y<<")\n";
    os<<"Size: "<<size.x<<" x "<<size.y<<")\n";

    sf::Color color = car.color;
    os<<"Color: ("<<color.r<<", "<<color.g<<", "<<color.b<<")\n";

    os<<"Speed: "<<car.speed<<'\n';
    os<<"Acceleration: "<<car.acceleration<<'\n';
    os<<"Max Speed: "<<car.maxSpeed<<'\n';
    os<<"Friction: "<<car.friction<<'\n';
    os<<"Angle: "<<car.angle<<'\n';

    os<<"\nControls:\n";
    os<<"Forward: "<<car.controls[0]<<'\n';
    os<<"Left: "<<car.controls[1]<<'\n';
    os<<"Right: "<<car.controls[2]<<'\n';
    os<<"Reverse: "<<car.controls[3];

    return os;
}

sf::Color Car::randomColor()
{
    std::random_device rd;
    std::uniform_int_distribution<unsigned int> range(0, 255);

    unsigned int rValue = range(rd);
    unsigned int gValue = range(rd);
    unsigned int bValue = range(rd);

    return sf::Color(rValue, gValue, bValue);
}
