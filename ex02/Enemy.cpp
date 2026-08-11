#include "Entity.hpp"

Enemy::Enemy(std::string name, int hp) : Entity(name), m_hp(hp){

            std::cout << "+ Enemy " + name + " \n";
        }

Enemy::~Enemy(){
    std::cout << "- Enemy " + m_name + " \n";
}
std:: string Enemy::describe() const{
    
    return "Enemy " + m_name + " Hp " + std::to_string(m_hp) + " " ;
}