#include "Entity.hpp"

#include <iostream>
#include <memory>
#include <vector>


int main()
{

    std::vector<std::unique_ptr<Entity>> party;
    party.push_back(std::make_unique<Player>("Aria"));
    party.push_back(std::make_unique<Enemy>("Goblin", 12));
    party.push_back(std::make_unique<Player>("Bran"));
    party.push_back(std::make_unique<Enemy>("Orc", 40));

    for (const auto& e : party)                 // single loop, base type only
        std::cout << e->describe() << '\n';
    // unique_ptr frees every element here; with raw Entity* you'd delete in a loop

}