
#ifndef HERO__KNIGHT_H
#define HERO__KNIGHT_H

#include "Hero.h"
#include <iostream>
#include <ctime>
using namespace std;

class Knight : public Hero {
public:
    Knight();
    void attack(Hero &enemy) override;
};


#endif //HERO__KNIGHT_H
