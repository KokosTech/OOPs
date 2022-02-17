#include <iostream>

using namespace std;

struct vector_t{
    int *data;
    size_t size;
    size_t capacity;
};

typedef struct vector_t vector_t;

vector_t init(size_t capacity = 2);
vector_t copyVector(vector_t &vector);

int at(const vector_t &vector);
int push_back(vector_t &vector, int element);
int resize(vector_t &vector);

void remove_back(vector_t &vector);
void destroy(vector_t &vector);
void printVector(vector_t &vector);

int main() {
    vector_t v = init();

    push_back(v, 1);
    push_back(v, 13);
    push_back(v, 16);
    push_back(v, 26);
    remove_back(v);

    vector_t nv = copyVector(v);
    printVector(nv);

    destroy(v);
    destroy(nv);
    return 0;
}

vector_t init(size_t capacity) {
    vector_t v;

    v.data = new int[capacity];
    v.size = 0;
    v.capacity = capacity;

    return v;
}

vector_t copyVector(vector_t &vector) {
    vector_t newVector;

    newVector.size = vector.size;
    newVector.capacity = vector.capacity;
    newVector.data = new int[vector.capacity];

    if(!newVector.data)
        return newVector;

    for(int i = 0; i < vector.size; ++i) 
        newVector.data[i] = vector.data[i];
    

    return newVector;
}

int at(const vector_t &vector, size_t index) {
    if(index >= vector.size)
        return -1;

    return vector.data[index];
}

int push_back(vector_t &vector, int element) {
    int success = 0;
    if(vector.size == vector.capacity)
        success = resize(vector);
    
    vector.data[vector.size++] = element;

    return success;
}

int resize(vector_t &vector) {
    vector.capacity *= 2;
    int *newData = new int[vector.capacity];
    if(!newData) 
        return 1;

    for(int i = 0; i < vector.size; ++i)
        newData[i] = vector.data[i];
    

    delete [] vector.data;
    vector.data = newData;

    return 0;
}

void remove_back(vector_t &vector) {
    if(vector.size == 0)
        return;
    --vector.size;
}

void destroy(vector_t &vector) {
    delete [] vector.data;
}

void printVector(vector_t &vector) {
    for(int i = 0; i < vector.size; ++i)
        cout << vector.data[i] << " ";
    cout << endl;
}

