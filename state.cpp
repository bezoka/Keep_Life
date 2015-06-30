#include "state.h"

State::State()
{
    Hunger = 100;
    Days = 0;
    Age = 0;
    Health = 100;

    if(rand()%2)
    {
        Sex = "Man";
        Pregnant = 0;
    }
    else
    {
        Sex = "Woman";

        Pregnant = (rand()%2)+1;
    }
}


int State::Update()
{
    Days++;

    if(Days % 10 == 0)

    {
        Hunger--;
    }

    if(Days>=365)
    {
        Days = 0;
        Age++;
    }


    if(Age>=70)
        if((rand()%100)==0)
    {

        return 1;
    }

    if(Hunger<=0 || Health<=0)
    {
        return 1;
    }

    return 0;
}


void State::Set_Health(int d_Health)
{
    Health += d_Health;
}


std::string State::Get_Sex()
{
    return Sex;
}


void State::Increase_Hunger(int d_Hunger)
{
    Hunger += d_Hunger;
}


int State::Get_Age()
{
    return Age;
}


int State::Get_Hunger()
{
    return Hunger;
}


int State::Get_Health()
{
    return Health;
}


int State::Get_Pregnant()
{
    return Pregnant;
}


void State::Set_Pregnant(int a)
{
    Pregnant += a;
}
