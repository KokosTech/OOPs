#pragma once
#include <iostream>

class Vector{
    private:
        size_t size;
        size_t capacity;
        int *data;
    public:
        // Constructors
        Vector();
        Vector(int capacity);

        // Getters / Setters
        size_t getSize();
        size_t getCapacity();

        // Vector methods
        Vector &push_back(const int &value);
        Vector &pop_back();
        Vector &resize();
        Vector &print();

        // Destructor
        ~Vector();
};