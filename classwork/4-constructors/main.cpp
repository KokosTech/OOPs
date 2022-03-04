#include<iostream>

using namespace std;

class Example{
    private:
        int count;
        int* arr;
    public: 
        Example(){
            cout<<"Hello from default constructor"<<endl;
        }

        Example(int i)
        :count(i), arr(new int[i]){
            cout<<"Hello from constructor"<<endl;

        }

        Example(const Example& rhs){
            cout<<"Hello from copy constructor"<<endl;
            this->count = rhs.count;
            this->arr = new int[rhs.count];
            for(int i = 0; i < rhs.count; ++i){
                this->arr[i] = rhs.arr[i];
            }
        }

        Example& operator=(const Example& rhs){
            cout << "Hello from assignment operator" << endl;
            if(this != &rhs){
                delete[] this->arr;
                this->count = rhs.count;
                this->arr = new int[rhs.count];
                for(int i = 0; i < rhs.count; ++i){
                    this->arr[i] = rhs.arr[i];
                }
            }
            return *this;
        }

        ~Example(){
            cout<<"Hello from destructor"<<endl;
        }

        void print()const{
            cout<<"In print"<<endl;
        }

};

int main(){
    Example e(1);
    Example e2(2);
    Example e3 = e2;
    e = e2;
/*     Example e2(2);
    Example e3 = e; // copy constructor
    e = e2; // copy assignment */
    e.print();

    //Example* e2 = new Example();

    //delete e2;

    return 0;
}