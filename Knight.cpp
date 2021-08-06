

#include "Knight.h"

Knight::Knight() : Hero()
{
    _damage = 15;
    _warriorClass="Knight";
}

void Knight::attack(const Hero &enemy) {
    unsigned int damage = rand() % 5 + _damage, OFTA = rand() % 3; // Outcome of the attack - Исход атаки
    cout << "\n(((___Knight_attack___)))";
    switch(OFTA)
    {
        case 1:
        {
            enemy.getDamage(damage);
            cout <<"\nThe knight successfully stabbed the enemy. "
                 <<"\nDamage dealt: " << damage; break;
        }
        case 2:
        {
            enemy.getDamage(damage/2);
            cout << "\nThe knight stumbled and dealt a bad blow. "
                 << "\nDamage dealt: " << damage/2; break;
        }
        case 3:
        {
            OFTA = rand() % 100;
            if(OFTA!=67)
                OFTA = rand() % 3;
            switch(OFTA)
            {
                case 1: cout << "\nThe knight stumbled and missed... "; break;
                case 2:
                {
                    OFTA = rand() % 4;
                    cout << "\nThe knight stumbled and fell. \nConsequences: ";
                    switch(OFTA)
                    {
                        case 1:
                        {
                            getDamage(5);
                            cout << "Knight twisted his leg."
                                 << "\nDamage dealt: " << 5
                                 << "\nRemaining health: " << getHP(); break;
                        }
                        case 2:
                        {
                            getDamage(15);
                            cout << "The knight broke his left arm on a stone. "
                                 << "\nDamage dealt: " << 15
                                 << "\nRemaining health: " << getHP(); break;
                        }
                        case 3:
                        {
                            getDamage(15);
                            setDamage(getDamage()/2);
                            cout << "The knight broke his right arm on a stone. "
                                 << "\nDamage dealt " << 15
                                 << "\nDamage reduced by 2 times. New damage: " << getDamage()
                                 << "   ( Since the knight is right-handed and cannot hold a sword in his left hand :) )"
                                 << "\nRemaining health: " << getHP(); break;
                        }
                        case 4:
                        {
                            getDamage(20);
                            cout << "Knight bruised knee. "
                                 << "\nDamage dealt: " << 20
                                 << "\nRemaining health: " << getHP();
                        }
                    }  break;
                }
                case 67:
                {
                    getDamage(100);
                    cout << "The knight hit his head hard on a stone and... He died. ";
                    return;
                }
            }
        }
    }
    cout << "\nOpponent's remaining health: " << enemy.getHP();
}
