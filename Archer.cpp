
#include "Archer.h"

Archer::Archer()
{
    _damage = 12;
    _warriorClass="Archer";
}

void Archer::attack(const Hero &enemy) {
    unsigned int damage = rand() % 5 + _damage, OFTA = rand() % 3; // Outcome of the attack - Исход атаки
    cout << "\n(((___Archer_attack___)))";
    switch(OFTA)
    {
        case 1:
        {
            enemy.getDamage(damage);
            cout <<"\nThe archer successfully stabbed the enemy. "
                 <<"\nDamage dealt: " << damage; break;
        }
        case 2:
        {
            enemy.getDamage(damage/2);
            cout << "\nThe archer stumbled and dealt a bad blow. "
                 << "\nDamage dealt: " << damage/2; break;
        }
        case 3:
        {
            OFTA = rand() % 100;
            if(OFTA!=67)
                OFTA = rand() % 3;
            switch(OFTA)
            {
                case 1: cout << "\nThe archer stumbled and missed... "; break;
                case 2:
                {
                    OFTA = rand() % 3;
                    cout << "\nThe archer stumbled and fell. \nConsequences: ";
                    switch(OFTA)
                    {
                        case 1:
                        {
                            getDamage(5);
                            cout << "Archer twisted his leg."
                                 << "\nDamage dealt: " << 5
                                 << "\nRemaining health: " << getHP(); break;
                        }
                        case 2:
                        {
                            getDamage(15);
                            setDamage(getDamage()/2);
                            cout << "The archer broke his arm on a stone. "
                                 << "\nDamage dealt " << 15
                                 << "\nDamage reduced by 2 times. New damage: " << getDamage()
                                 << "   ( Since with a broken arm, an archer will not be able to shoot from a bow )"
                                 << "\nRemaining health: " << getHP(); break;
                        }
                        case 3:
                        {
                            getDamage(20);
                            cout << "Archer bruised knee. "
                                 << "\nDamage dealt: " << 20
                                 << "\nRemaining health: " << getHP();
                        }
                    }  break;
                }
                case 67:
                {
                    getDamage(100);
                    cout << "The archer hit his head hard on a stone and... He died. ";
                    return;
                }
            }
        }
    }
    cout << "\nOpponent's remaining health: " << enemy.getHP();
}
