#include "Entity.hpp"

Player::Player(std::string name) : Entity(name){

    //std::cout<< "+Entity " + m_name + " \n";
    std::cout<< "+ Player " << m_name << " \n";
}

Player::~Player(){
    std::cout<< "- Player " << m_name << " \n";
}

std::string Player::describe() const{
    return "Player " + m_name + " " ;
}