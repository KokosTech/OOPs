#pragma once 
#include <iostream>
#include "Zoo.hpp"

class Animal {
    private:
        char *name;
        char *type;
        unsigned short age;
        double avg_age;
    public:
        Animal();
        Animal(char *name);
        Animal(char *name, char *type, unsigned short age);
        Animal(char *name, char *type, unsigned short age, double avg_age);

        Animal(const Animal &rhs);
        Animal &operator=(const Animal &rhs);

        void setName(char *name);
        void setAge(unsigned short age);
        void setAvgAge(double avg_age);

        char *getName()const;
        char *getType()const;
        unsigned short getAge()const;
        double getAvgAge()const;

        void print()const;

        ~Animal();
};
