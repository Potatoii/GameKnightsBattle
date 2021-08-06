
#ifndef HERO__ARCHER_H
#define HERO__ARCHER_H

#include "Hero.h"
#include <iostream>
#include <ctime>
using namespace std;

class Archer : public Hero {
private:
public:
    Archer();
    void attack(Hero &enemy) override;
};


#endif //HERO__ARCHER_H
