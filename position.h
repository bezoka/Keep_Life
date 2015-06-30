#ifndef POSITION_H
#define POSITION_H

#include <stdlib.h>

#include <iostream>

class Position
{
public:
    Position();
    void Set_Position(int d_x, int d_y);
    int Get_x();
    int Get_y();

protected:
    int x, y;
};

#endif // POSITION_H
