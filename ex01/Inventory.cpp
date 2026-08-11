#include "Entity.hpp"

Inventory::Inventory(const std::string& owner, std::initializer_list<std::string> items) 
    : 
        m_owner(owner), m_count(items.size()), m_items(new std::string[m_count]){

            std::size_t i = 0;

            for (const std::string& item : items)
            {
                m_items[i] = item;
                ++i;
            }
        }
        
Inventory::~Inventory(){
    delete [] m_items;
}