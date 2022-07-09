#include "Window.hpp"
#include "Car.hpp"
#include <ctime>

int main(int argc, char** argv)
{
    srand((unsigned int)time(nullptr));
    unsigned int width = 1200;
    unsigned int length = 600;

    if(argc == 3)
    {
        width = atoi(argv[1]);
        length = atoi(argv[2]);
    }

    Window window("Car", width, length);
    Car car(width / 2 - width / 20, length / 2 - length / 20, width / 10, length / 10);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }

                default:
                {
                    break;
                }
            }
        }

        window.clear();
        window.draw(car);
        window.display();
    }

    return 0;
}
