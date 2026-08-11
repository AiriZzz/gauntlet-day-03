#pragma once
#include <string>
#include <algorithm>
#include <iostream>

class Entity {
    public:
        explicit Entity(std::string name, int maxHp);
        virtual void takeDamage(int amount);       //default: take full damage
        void heal(int amount);
        bool isAlive() const;                      //if current hp>0
        int currentHP() const;
        int maxHP() const;
        virtual std::string describe() const= 0;   // pure virtual
        virtual ~Entity();                         // virtual!
    protected:
        std::string m_name;
    private:
        int m_maxHp;
        int m_currentHp;                           // invariant: 0 <= m_currentHp <= m_maxHp; only the methods below touch it

};

class Player : public Entity {
    public:
        explicit Player(std::string name, int hp, int armor);          //ex02 player have name, hp, armor
        virtual void takeDamage(int amount) override;
        //~Player() = default;
        int currentArmor() const;
        std::string describe() const override;      // -> "Player <name>"
    
    private:
    int m_armor;

};

class Enemy : public Entity {
public:
    Enemy(std::string name, int hp);            // name AND hp, both required
    //~Enemy() = default;                          // implicitly virtual (base dtor is virtual)
    std::string describe() const override;      // -> "Enemy <name> (hp N)"
    
};