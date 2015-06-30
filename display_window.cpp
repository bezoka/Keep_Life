#include "display_window.h"

Display_Window::Display_Window()
{
    Window.create(sf::VideoMode(1920, 1200), "Keep Life Simulation");

    View_Window.setCenter(0, 0);
    View_Window.setSize(3000, 1500);


}


void Display_Window::Display()
{


    Window.clear();

    Window.draw(&Pixels[0], Pixels.size(), sf::Points);

    Window.setView(View_Window);

    Window.display();

    Pixels.resize(0);
}


void Display_Window::Set_People_Pixels(int x, int y)
{
    Pixels.push_back(sf::Vertex( sf::Vector2f(x, y), sf::Color::Red));
}


void Display_Window::Set_Foods_Pixels(int x, int y)
{
    Pixels.push_back(sf::Vertex( sf::Vector2f(x, y), sf::Color::Blue));
}


void Display_Window::Handling()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        View_Window.zoom(1.01f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
        View_Window.zoom(0.99f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        View_Window.move(-30, 0);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        View_Window.move(30, 0);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        View_Window.move(0, -30);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        View_Window.move(0, 30);
    }
}
