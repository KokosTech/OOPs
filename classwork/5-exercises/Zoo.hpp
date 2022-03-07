#pragma once 
#include <iostream>
#include "Animal.hpp"

class Zoo {
    private:
        char *manager_name;
        Animal *animals;
        std::size_t size = 0, capacity = 0;
        char *address;
        uint32_t price; // $5.00 -> 500 - non-float-currency
    public:
        Zoo();
        Zoo(size_t capacity);
        Zoo(char *manager_name, char *address, uint32_t price, size_t capacity);
        
        Zoo(const Zoo &rhs);
        Zoo &operator=(const Zoo &rhs);

        ~Zoo();
        void addAnimal(Animal *animal);
        void print()const;
};
