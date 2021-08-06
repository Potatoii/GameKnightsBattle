#include "Hero.h"

int Hero::getHP() {
    return _HP;
}

void Hero::setHP(int HP) {
    _HP = HP;
}

void Hero::setDamage(int newDamage) {
    _damage=newDamage;
}

const char *Hero::getClass() {
    return _warriorClass;
}

Hero::~Hero() {
    delete[] _warriorClass;
}

Hero::Hero() {}

void Hero::getDamage(int damage) {
    _HP -= damage;
}
