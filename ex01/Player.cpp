#include "Entity.hpp"

Player::Player(std::string name) : Entity(name){}
std::string Player::describe() const{
    return "Player " + m_name + " " ;
}