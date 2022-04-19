#include <iostream>
#include "Book.hpp"
#include "Library.hpp"

using namespace std;

int main(){
    Book b1("Random Chat", "Park Eun Hyuk", 190);
    Book bs[] = {Book("Bastard", "Carnby Kim", 94), Book("It's mine", "LuckS", 156), Book("Lookism", "Taejun Pak", 378)};
    Library l(bs, 3);
    l.add(b1);
    l.printLibrary();
    cout << "==========================" << endl;
    l.lendBook("Bastard");
    l.lendBook("Random Chat");
    l.returnBook("Bastard");
    l.printLibrary();
    cout << "==========================" << endl;

    Library l2(3);
    l2.add(b1);
    l2.printLibrary();
    cout << "==========================" << endl;
    l2 = l;
    l2.printLibrary();
    cout << "==========================" << endl;

    return 0;
}