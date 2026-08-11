#include "Entity.hpp"

Inventory::Inventory(const std::string& owner, std::initializer_list<std::string> items) 
    : 
        m_owner(owner), m_count(items.size()), m_items(new std::string[m_count]){

            std::cout << "+ Inventory " << owner << " (";

            std::size_t i = 0;

            for (const std::string& item : items)
            { 
                m_items[i] = item;
                std::cout << item;
                if (i + 1 < m_count)
                {
                    std::cout << ", ";
                }

                ++i;
            }

            std::cout << ") \n";            
        }

Inventory::~Inventory(){

            std::cout << "- Inventory " << m_owner << " (";

            std::size_t i = 0;

            for (; i < m_count; ++i)
            { 
                std::cout << m_items[i];

                if (i + 1 < m_count)
                {
                    std::cout << ", ";
                }


            }

            std::cout << ") \n";
    
            delete [] m_items;
}