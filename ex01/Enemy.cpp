#include "Entity.hpp"

Enemy::Enemy(std::string name, int hp, std::initializer_list<std::string> loot) 
    : 
        Entity(name), m_hp(hp), m_bag(name, loot){}


std:: string Enemy::describe() const{
    
    return "Enemy " + m_name + " Hp " + std::to_string(m_hp) + " " ;
}