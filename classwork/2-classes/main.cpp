#include <iostream>
#include "Vector.hpp"

using namespace std;

int main() {
    Vector v(4);
    cout << v.getCapacity() << endl;
    v.push_back(1).push_back(2).push_back(3).push_back(4).push_back(5).push_back(6).pop_back();
    v.print();
    v.~Vector();
    return 0;
}