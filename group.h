#ifndef GROUP_H
#define GROUP_H

#include "human.h"
#include "item.h"
#include "building.h"
#include <vector>

class Group
{
public:
    Group();
private:
    std::vector <Human> Humans;
    std::vector <Item> Storage;
    std::vector <Building> Buildings;
};

#endif // GROUP_H
