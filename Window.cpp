#include "Window.hpp"

Window::Window(const char* title, unsigned int width, unsigned int length)
:sf::RenderWindow(sf::VideoMode(width, length), title), name(title)
{
    setFramerateLimit(FRAMERATE);
}

Window::Window(const char* title, const sf::Vector2u& dimensions)
:Window(title, dimensions.x, dimensions.y)
{

}

Window::Window(const Window& window)
:Window(window.name, window.getSize())
{

}

Window& Window::operator =(const Window& window)
{
    Window(window.name, window.getSize());
    return *this;
}

std::ostream& operator <<(std::ostream& os, const Window& window)
{
    os<<"Name: "<<window.name<<'\n';
    const sf::Vector2u dimensions = window.getSize();
    os<<"Dimensions: ("<<dimensions.x<<" x "<<dimensions.y<<')';

    return os;
}
