#include "Vector.hpp"

Vector::Vector(){
    this->size = 0;
    this->capacity = 2;
    this->data = new int[this->capacity];
}

Vector::Vector(int capacity){
    this->size = 0;
    this->capacity = capacity;
    this->data = new int[this->capacity];
}

size_t Vector::getSize(){
    return this->size;
}

size_t Vector::getCapacity(){
    return this->capacity;
}

Vector &Vector::resize(){
        this->capacity *= 2;
        int *newData = new int[this->capacity];
        
        for(int i = 0; i < this->size; ++i)
            newData[i] = this->data[i];
        
        delete[] this->data;
        this->data = newData;
    return *this;
}

Vector &Vector::push_back(const int &value){
    if(this->size == this->capacity){
        this->resize();
    }
    this->data[this->size++] = value;
    
    return *this;
}

Vector &Vector::pop_back(){
    if(this->size == 0){
        return *this;
    }
    this->size--;
    return *this;
}

Vector &Vector::print(){
    for(int i = 0; i < this->size; ++i)
        std::cout << this->data[i] << " ";
    std::cout << std::endl;
    return *this;
}

Vector::~Vector(){
    this->capacity = 0;
    this->size = 0;
    delete[] this->data;
    this->data = nullptr;
}