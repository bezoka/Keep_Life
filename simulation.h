#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <math.h>

#include "human.h"
#include "food.h"

//testowane
#include "group.h"
#include "item.h"

class Simulation
{
public:
    Simulation();
    void Simulate();
    void Check_Food();
    void Check_Human();
    void Search_Woman();
    void Do();

    void Search_Food();

    std::vector <Human> People;
    std::vector <Food> Foods;

    //testowane
    std::vector <Group> Groups;
    std::vector <Item> Items;
};

#endif // SIMULATION_H
