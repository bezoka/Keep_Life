#ifndef HUMAN_H
#define HUMAN_H

#include "position.h"
#include "state.h"
#include <QString>

class Human
{
public:
    Human();
    int Update();
    void Move(int d_x, int d_y);
    void Do_Something();
    int Hit();
    int Get_Hit(int d_h);
    void Eat();
    void Set_Goal(int dx, int dy);
    int Get_Goal_x();
    int Get_Goal_y();
    Position Get_Position();
    State Get_States();
private:
    Position H_Position;
    int Goal_x;
    int Goal_y;
    State States;
};

#endif // HUMAN_H
