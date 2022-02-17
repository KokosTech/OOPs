#include <iostream>

using namespace std;

struct vector_t{
    int *data;
    size_t capacity;
    size_t size;
};

typedef struct vector_t vector_t;

vector_t &init(size_t capacity = 2){
    vector_t v;
    v.data = new int[capacity];
    v.capacity = capacity;
    v.size = 0;

    return v;
}

void destroy(vector_t &v){
    delete [] v.data;
}

// HW - push_back, pop_back, copy

int main(){
    vector_t v = init(); // capacity = 2
    vector_t v2 = init(10); // capacity = 10
    vector_t *ptr = &v;
    destroy((*ptr));
    destroy(v2);
    return 0;
}