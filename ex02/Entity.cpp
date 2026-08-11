#include "Entity.hpp"

Entity::Entity(std::string name, int maxHp) : m_name(name), m_maxHp(maxHp){ m_currentHp = m_maxHp;}

bool Entity::isAlive() const
{

return m_currentHp > 0;

}

Entity::~Entity(){
    std::cout << "- Entity " + m_name + "\n";
}

int Entity::currentHP() const{

    return m_currentHp;
}

int Entity::maxHP() const{

    return m_maxHp;
}

void Entity::takeDamage(int amount){
    int before  = m_currentHp;
    m_currentHp = std::max(0, m_currentHp - amount);          // clamp at 0
    std::cout << m_name << " takes " << amount << " damage ("
              << before << " -> " << m_currentHp << " hp)\n";
}

void Entity::heal(int amount){ m_currentHp = std::min(m_maxHp, m_currentHp + amount); }