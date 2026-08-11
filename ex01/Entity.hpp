#pragma once
#include <string>
#include <initializer_list>
#include <algorithm>

// Inventory.hpp: a resource that must be released
class Inventory {
public:
    Inventory(const std::string& owner, std::initializer_list<std::string> items);
    ~Inventory();                                      // delete[] here, prints '-'

    Inventory(const Inventory&)            = delete;   // owns a raw buffer:
    Inventory& operator=(const Inventory&) = delete;   //   forbid copies (no double free)
private:
    std::string  m_owner;
    std::size_t  m_count;
    std::string* m_items;   // new std::string[m_count] of item names, freed in ~Inventory
};

class Entity {
public:
    explicit Entity(std::string name);
    virtual std::string describe() const= 0;   // pure virtual
    virtual ~Entity() = default;                         // virtual!
protected:
    std::string m_name;
};

class Player : public Entity {
public:
    explicit Player(std::string name);          // name only: players have no hp here
    std::string describe() const override;      // -> "Player <name>"
};

class Enemy : public Entity {
public:
    Enemy(std::string name, int hp, std::initializer_list<std::string> loot);            // name AND hp, both required
    ~Enemy() = default;                          // implicitly virtual (base dtor is virtual)
    std::string describe() const override;      // -> "Enemy <name> (hp N)"
private:
    int m_hp;
    Inventory m_bag;   // built after the Entity base, destroyed before it
};