#include "position.h"

#define WORLD 1000

Position::Position()
{
    switch (rand()%4)
    {
    case 0:
        Set_Position(rand() % WORLD, rand() % WORLD);
        break;
    case 1:
        Set_Position(-(rand() % WORLD), rand() % WORLD);
        break;
    case 2:
        Set_Position(rand() % WORLD, -(rand() % WORLD));
        break;
    case 3:
        Set_Position(-(rand() % WORLD), -(rand() % WORLD));
    default:
        break;
    }

}


void Position::Set_Position(int d_x, int d_y)
{
    x = d_x;
    y = d_y;
}


int Position::Get_x()
{
    return x;
}


int Position::Get_y()
{
    return y;
}

