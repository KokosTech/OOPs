#include <iostream>

// Encapsulation - protect / hide data from the outside (users)

// Revision
// Class - a collection of data and methods
// Object - an instance of a class
// Инстанция = Екземпляр

// "Plan"
// 1. Consteructors - default, copy, move
// 2. Destructor - delete object & heap memory

// The life of an object

using namespace std;

class Example{
    private:
        int count;
    public:
        Example(){
            cout << "Hello, from the default constructor" << endl;
        }

        Example(int i)
        : count(i){
            cout << "Hello, from the constructor with parameter" << endl;
        }

        // Slower
/*         Example(int count){
            this->count = count;
            cout << "Hello, from the constructor with parameter" << endl;
        } */

        ~Example(){
            cout << "Goodbye, from the destructor" << endl;
        }

        // const int *arr -> can't change the vals
        // int *const arr -> can't change the ref
        // const int *const arr -> can't change the vals or ref - aka NO BITCHES

        // arr& - you can change the vals
        // conts arr& -> NO BITCHES

        void print()const{
            //count++; // това не е етично - трюбва да слохим CONST, за да е етично и да не може да променяме данните от PUBLIC funcs - да не променяме вътрешното състояние  
            //cout << "Hello, from the print method" << endl;
            cout << this->count << endl;
        }
};

int main(){
    Example example(1);
    example.print();

    Example* example2 = new Example();
    delete example2;
    return 0;
}