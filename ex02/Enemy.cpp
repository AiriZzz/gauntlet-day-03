#include "Entity.hpp"

Enemy::Enemy(std::string name, int hp) : Entity(name, hp){}

std:: string Enemy::describe() const{
    
    return "Enemy " + m_name + " Hp (" + std::to_string(Entity::currentHP()) + " / " + std::to_string(Entity::maxHP()) + ") "
    + std::to_string(Entity::isAlive());
}