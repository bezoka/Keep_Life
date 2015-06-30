#ifndef STATE_H
#define STATE_H

#include <string>
#include <stdlib.h>
#include <iostream>

class State
{
public:
    State();
    int Update();
    void Set_Health(int d_Health);
    std::string Get_Sex();
    void Increase_Hunger(int d_Hunger);
    int Get_Age();
    int Get_Hunger();
    int Get_Health();
    int Get_Pregnant();
    void Set_Pregnant(int a);



private:
    std::string Sex;
    int Age;
    int Health;
    int Hunger;
    int Days;
    int Pregnant;

};

#endif // STATE_H
