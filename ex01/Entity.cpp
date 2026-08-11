#include "Entity.hpp"

Entity::Entity(std::string name) : m_name(name){

    std::cout << "+ Entity " + m_name + "\n";
}

Entity::~Entity(){
    std::cout << "- Entity " + m_name + "\n";
}

/*Player::Player(std::string name) : Entity(name){}
std::string Player::describe() const{
    return "Player " + m_name + " " ;
}

Enemy::Enemy(std::string name, int hp) : Entity(name), m_hp(hp){}
std:: string Enemy::describe() const{
    
    return "Enemy " + m_name + " Hp " + std::to_string(m_hp) + " " ;
}*/