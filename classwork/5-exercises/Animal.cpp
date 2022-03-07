#include "Animal.hpp"

Animal::Animal(char *name) {
    this->name = strdup(name);
    this->type = strdup("Unknown");
    this->age = 0;
    this->avg_age = 0;
}

Animal::Animal(char *name, char *type, unsigned short age)
: age(age){
    this->name = strdup(name);
    this->type = strdup(type);
    this->age = age;
    this->avg_age = 0;
}

Animal::Animal(char *name, char *type, unsigned short age, double avg_age)
: age(age), avg_age(avg_age){
    this->name = strdup(name);
    this->type = strdup(type);
    this->age = age;
    this->avg_age = avg_age;
}

Animal::Animal(const Animal &rhs)
: age(rhs.age), avg_age(rhs.avg_age){
    this->name = strdup(rhs.name);
    this->type = strdup(rhs.type);
}

Animal::Animal &Animal::operator=(const Animal &rhs){
    if (this != &rhs){
        this->name = strdup(rhs.name);
        this->type = strdup(rhs.type);
        this->age = rhs.age;
        this->avg_age = rhs.avg_age;
    }
    return *this;
}

void Animal::setName(char *name){
    if(name == NULL)
        return;

    if(this->name != nullptr)
        delete[] this->name;
    
    this->name = strdup(name);
}

void Animal::setAge(unsigned short age){
    this->age = age;
}

void Animal::setAvgAge(double avg_age){
    this->avg_age = avg_age;
}

char *Animal::getName()const{
    return this->name;
}

char *Animal::getType()const{
    return this->type;
}

unsigned short Animal::getAge()const{
    return this->age;
}

double Animal::getAvgAge()const{
    return this->avg_age;
}

void Animal::print()const{
    std::cout << "------------------------------" << std::endl;
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Type: " << this->type << std::endl;
    std::cout << "Age: " << this->age << std::endl;
    std::cout << "Avg age: " << this->avg_age << std::endl;
    std::cout << "------------------------------" << std::endl << std::endl;
}

Animal::~Animal() {
    delete[] name;
    delete[] type;
}