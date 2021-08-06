
#ifndef HERO__HERO_H
#define HERO__HERO_H

#include <iostream>
using namespace std;

class Hero {
protected:
    unsigned int _damage;
private:
    int _HP=100;
    const char* _warriorClass;
public:
    int getHP();
    int getDamage();
    const char *getClass();
    void getDamage(int damage);
    void setDamage(int newDamage);
    virtual void attack(Hero &enemy)=0;
    Hero();
    ~Hero();
};


#endif //HERO__HERO_H
