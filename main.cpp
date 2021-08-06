#include <iostream>
#include "Hero.h"
#include "Archer.h"
#include "Knight.h"
using namespace std;
unsigned int* ChoiceOfFighters()
{
    unsigned int* choice = new unsigned int[2];
    for(size_t i=0;i<2;i++)
    {
        cout << "\nSelect fighter number " << i+1
        << "\n1: Knight, 2: Archer. Enter the fighter's number: ";
        cin >> choice[i];
    }
    return choice;
}
Hero** makeHeroes(unsigned int* choice)
{
    Hero** heroes = new Hero*[2];
    for(size_t i=0;i<2;i++)
        switch(choice[i])
        {
            case 1:
            {
                Knight *knight=new Knight();
                heroes[i]=knight; break;
            }
            case 2:
            {
                Archer archer;
                heroes[i]=&archer;
            }
        }
    return heroes;
}
bool winner(Hero &hero)
{
    cout << "Winner is " << hero.getClass()
    << "\nGame over, would you like to start a new game? "
    << "\n  Enter any number other than 0 to start the game. 0 To complete the work.";
    int result;
    cin >> result;
    return result == 0 ? 0 : 1;
}
int game()
{
    cout << "    ___N_E_W__G_A_M_E___";
    unsigned int* choice = ChoiceOfFighters();
    Hero** heroes = makeHeroes(choice);
    cout << "\nFirst move...";
    while(true)
    {
        (*heroes)[0].attack((*heroes)[1]);
        if((*heroes)[0].getHP()<1||(*heroes)[1].getHP()<1)
            break;
        (*heroes)[1].attack((*heroes)[0]);
        if((*heroes)[0].getHP()<1||(*heroes)[1].getHP()<1)
            break;
    }
    return ((*heroes)[0].getHP()<1 ? winner((*heroes)[1])==1 ? game() : 0 : winner((*heroes)[0])) == 1 ? game() : 0;
}

int main() {
    srand(time(nullptr));
    game();
    return 0;
}
