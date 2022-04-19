#include <iostream>
#include <store/Product.hpp>
#include <store/Property.hpp>
#include <store/Store.hpp>

using namespace std;

void printMenu() {
    cout << "1. Add product" << endl;
    cout << "2. Check product quantity" << endl;
    cout << "3. Check product price" << endl;
    cout << "4. Restock product" << endl;
    cout << "5. Change process price" << endl;
    cout << "6. Buy product" << endl;
    cout << "7. Show shop's information" << endl;
    cout << "8. Exit" << endl;
    cout << "Choose an option: ";
}

void setupStore(string &name, string &addr, string &type, double &baseRent) {
    cout << "Enter the name of the store: ";
    getline(cin, name);
    cout << "Enter the address of the store: ";
    getline(cin, addr);
    cout << "Enter the type of the store: ";
    getline(cin, type);
    cout << "Enter the base rent of the store: ";
    cin >> baseRent;
}

int main() {
    cout << "Hello, World!" << std::endl;

    string storeName, storeAddr, storeType;
    double baseRent;
    uint cmd;

    setupStore(storeName, storeAddr, storeType, baseRent);

    do {
        printMenu();
        cin >> cmd;
        switch (cmd) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    } while (cmd != 8);

    return 0;
}