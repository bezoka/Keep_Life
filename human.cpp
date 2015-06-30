#include "human.h"

Human::Human()
{
    Goal_x = 0;
    Goal_y = 0;
}


int Human::Update()
{
    if(States.Update())
        return 1;
    else
        return 0;
}


void Human::Move(int d_x, int d_y)
{
    H_Position.Set_Position(H_Position.Get_x() + d_x, H_Position.Get_y() + d_y);
}


void Human::Do_Something()
{
    int value_x = Goal_x - H_Position.Get_x();
    int value_y = Goal_y - H_Position.Get_y();

    if(value_x>value_y || value_y==0)
    {
        if(value_x>0)
        {
            Move(1, 0);
        }
        if(value_x<0)
        {
            Move(-1, 0);

        }
    }

    if(value_y>value_x || value_x==0)
    {
        if(value_y>0)
        {
            Move(0, 1);

        }

        if(value_y<0)
        {
            Move(0, -1);

        }
    }

    if(value_x==value_y)
    {
        if(value_x>0)
        {
            Move(1,0);

        }
        if(value_x<0)
        {
            Move(-1,0);

        }
        if(value_y<0)
        {
            Move(0, -1);

        }
        if(value_y>0)
        {
            Move(0, 1);

        }
    }

    if(Goal_x==0 && Goal_y==0)
    {
        if(rand()%2)
            Move(rand()%5, rand()%5);
        else
            Move(-rand()%5, -rand()%5);

    }


}


int Human::Hit()
{
    return States.Get_Age();
}


int Human::Get_Hit(int d_h)
{
    States.Set_Health(-d_h);
    return States.Get_Health();
}


void Human::Eat()
{
    States.Increase_Hunger(10);
}


void Human::Set_Goal(int dx, int dy)
{
    Goal_x = dx;
    Goal_y = dy;
}


int Human::Get_Goal_x()
{
    return Goal_x;
}


int Human::Get_Goal_y()
{
    return Goal_y;
}


Position Human::Get_Position()
{
    return H_Position;
}


State Human::Get_States()
{
    return States;
}
