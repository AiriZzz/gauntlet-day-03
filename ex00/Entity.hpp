#pragma once
#include <string>

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
    Enemy(std::string name, int hp);            // name AND hp, both required
    std::string describe() const override;      // -> "Enemy <name> (hp N)"
private:
    int m_hp;
};