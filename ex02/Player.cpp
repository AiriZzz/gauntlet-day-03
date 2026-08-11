#include "Entity.hpp"

Player::Player(std::string name, int hp, int armor) : Entity m_name(name), m_hp(hp){

    //std::cout<< "+Entity " + m_name + " \n";
    std::cout<< "+ Player " << m_name << " \n";
}

int Player::currentArmor() const{

    return m_armor;
}

// Player.cpp: armor soaks part of the hit, min 1 damage gets through
void Player::takeDamage(int amount){
    int reduced = std::max(1, amount - m_armor);
    std::cout << m_name << "'s armor soaks " << (amount - reduced) << '\n';
    Entity::takeDamage(reduced);   // delegate: base applies the hit and logs it
}

Player::~Player(){
    std::cout<< "- Player " << m_name << " \n";
}


std::string Player::describe() const{
    return "Player " + m_name + " (HP " + std::to_string(Entity::currentHP()) + "/" + std::to_string(Entity::maxHP()) 
    + ", armor" + std::to_string(Player::currentArmor()) + ")";
}