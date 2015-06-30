#include "simulation.h"

Simulation::Simulation()
{

}


void Simulation::Simulate()
{
    Search_Woman();
    Search_Food();

    Check_Food();
    Check_Human();

    Do();

    Foods.resize(Foods.size()+1);
}


void Simulation::Check_Food()
{
    for(unsigned int i=0; i<People.size(); i++)
    {
        for(unsigned int j=0; j<Foods.size(); j++)
        {
            if( People[i].Get_Position().Get_x() == Foods[j].Get_Position().Get_x() )
            {
                if( People[i].Get_Position().Get_y() == Foods[j].Get_Position().Get_y() )
                {
                    People[i].Eat();
                    Foods.erase(Foods.begin()+j);
                }
            }
        }
    }
}


void Simulation::Check_Human()
{
    for(unsigned int i=0; i<People.size(); i++)
    {
        for(unsigned int j=0; j<People.size(); j++)
        {
            if(i!=j)
            {
                if( (People[i].Get_Position().Get_x() == People[j].Get_Position().Get_x() ) && ( People[i].Get_Position().Get_y() == People[j].Get_Position().Get_y()) )
                {
                    if(People[i].Get_States().Get_Sex() == People[j].Get_States().Get_Sex())
                    {
                        if(People[i].Get_Hit(People[j].Hit()) <= 0)
                        {
                            People.erase(People.begin() + i);
                        }
                    }
                }
            }
        }
    }

    for(unsigned int i=0; i<People.size(); i++)
    {
        for(unsigned int j=0; j<People.size(); j++)
        {
            if(j!=i)
            {
                if((People[i].Get_Position().Get_x()==People[j].Get_Position().Get_x()) && (People[i].Get_Position().Get_y()==People[j].Get_Position().Get_y()))
                {
                    if( People[i].Get_States().Get_Sex() != People[j].Get_States().Get_Sex() )
                    {
                        if(People[i].Get_States().Get_Pregnant() >= 1)
                        {
                            if(People[i].Get_States().Get_Hunger()>=1000)
                            {
                                if(People[i].Get_States().Get_Age() >= 5)
                                {
                                    if(People[j].Get_States().Get_Age() >= 5)
                                    {
                                        std::cout << People[i].Get_States().Get_Pregnant() << " ";
                                        People[i].Get_States().Set_Pregnant(-1);
                                        People.resize(People.size()+1);
                                        std::cout << People[i].Get_States().Get_Pregnant() << std::endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}



void Simulation::Do()
{

    for(unsigned int i=0; i<People.size(); i++)
    {
        People[i].Do_Something();
    }

    for(unsigned int i=0; i<People.size(); i++)
    {
        if(People[i].Update())
        {
            People.erase(People.begin()+i);
        }
    }
}


void Simulation::Search_Food()
{
    int v_x=0;
    int v_y=0;

    for(unsigned int i=0; i<People.size(); i++)
    {
        if( (People[i].Get_States().Get_Hunger()<5000 ) )
        {
            for(unsigned int j=0; j<Foods.size(); j++)
        {
            if(sqrt(pow(v_x-People[i].Get_Position().Get_x(), 2) + pow(v_y-People[i].Get_Position().Get_y(), 2) ) // pierwszy warunek
                    > // porownanie
               sqrt(pow(Foods[j].Get_Position().Get_x() - People[i].Get_Position().Get_x(), 2) + pow(Foods[j].Get_Position().Get_y() - People[i].Get_Position().Get_y(), 2) )) // drugi warunek
                {
                            v_x = Foods[j].Get_Position().Get_x();
                            v_y = Foods[j].Get_Position().Get_y();
                }
        }
            People[i].Set_Goal(v_x, v_y);
        }
        else
        {

        }
    }
}


void Simulation::Search_Woman()
{
    int v_x=0;
    int v_y=0;

    for(unsigned int i=0; i<People.size(); i++)
    {
        if(People[i].Get_States().Get_Sex()=="Man")
            if(People[i].Get_States().Get_Age()>=15)
        if( (People[i].Get_States().Get_Hunger()>5000 ) )  // czy najedzony
        for(unsigned int j=0; j<People.size(); j++)
        {
            if(sqrt(pow(v_x-People[i].Get_Position().Get_x(), 2) + pow(v_y-People[i].Get_Position().Get_y(), 2))
                    >
                   sqrt(pow(People[j].Get_Position().Get_x() - People[i].Get_Position().Get_x(), 2) + pow(People[j].Get_Position().Get_y() - People[i].Get_Position().Get_y(), 2) ))
                if(People[i].Get_States().Get_Pregnant()>0)
                {
                    {
                        v_x = People[j].Get_Position().Get_x();
                        v_y = People[j].Get_Position().Get_y();
                    }
                }
        }

        People[i].Set_Goal(v_x, v_y);
    }
}
