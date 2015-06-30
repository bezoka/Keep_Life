#ifndef DISPLAY_WINDOW_H
#define DISPLAY_WINDOW_H

#include "SFML/Graphics.hpp"
#include <vector>

class Display_Window
{
public:
    Display_Window();
    void Display();
    void Set_People_Pixels(int x, int y);
    void Set_Foods_Pixels(int x, int y);

    void Handling();

private:
    sf::RenderWindow Window;
    sf::View View_Window;
    std::vector <sf::Vertex> Pixels;
};

#endif // DISPLAY_WINDOW_H
