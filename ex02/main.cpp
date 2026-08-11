#include "Entity.hpp"
#include <memory>
#include <vector>


int main()
{
    // main.cpp
    Enemy  goblin("Goblin", 12);      // 12 hp, no armor
    Player hero("Aria", 30, 5);       // 30 hp, 5 armor

    Entity* a = &goblin;              // same static type ...
    Entity* b = &hero;               //   ... different runtime behavior
    
    a->takeDamage(8);                // Enemy: full 8            -> 4/12
    b->takeDamage(8);                // Player: 8 - 5 armor = 3  -> 27/30

    std::cout << goblin.describe() << '\n';
    std::cout << hero.describe()   << '\n';

    goblin.takeDamage(100);          // overkill clamps at 0, never negative
    hero.heal(999);                  // over-heal clamps at max, never above 30

    std::cout << goblin.describe() << '\n';
    std::cout << hero.describe()   << '\n';

}