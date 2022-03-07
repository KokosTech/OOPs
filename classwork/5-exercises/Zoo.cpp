#include "Zoo.hpp"
#include "Animal.hpp"

Zoo::Zoo()
:   manager_name(nullptr), 
    animals(nullptr), size(0), 
    capacity(0),
    address(nullptr), 
    price(0) {}

Zoo::Zoo(size_t capacity) : capacity(capacity) {
    this->animals = new Animal::Animal[capacity];
}

Zoo::Zoo(char *manager_name, char *address, uint32_t price, size_t capacity)
:price(price), capacity(capacity) {
    this->manager_name = strdup(manager_name);
    this->address = strdup(address);
    this->animals = new Animal::Animal[capacity];
}

Zoo::Zoo (const Zoo &rhs){
    this->manager_name = strdup(rhs.manager_name);
    this->address = strdup(rhs.address);
    this->price = rhs.price;
    this->capacity = rhs.capacity;
    this->animals = new Animal::Animal[capacity];
    for (size_t i = 0; i < rhs.size; i++)
        this->animals[i] = rhs.animals[i];
}

Zoo::Zoo &Zoo::operator=(const Zoo &rhs){
    if (this != &rhs){
        this->manager_name = strdup(rhs.manager_name);
        this->address = strdup(rhs.address);
        this->price = rhs.price;
        this->capacity = rhs.capacity;
        this->animals = new Animal::Animal[capacity];
        for (size_t i = 0; i < rhs.size; i++)
            this->animals[i] = rhs.animals[i];
    }
    return *this;
}

Zoo::~Zoo() {
    delete[] this->animals;
    delete[] this->manager_name;
    delete[] this->address;
}