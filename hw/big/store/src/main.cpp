#include <iostream>
#include <string>
#include <limits>

#include <store/Product.hpp>
#include <store/Property.hpp>
#include <store/Store.hpp>

using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void printMenu() {
    cout << "1. Add product" << endl;
    cout << "2. Check product quantity" << endl;
    cout << "3. Check product price" << endl;
    cout << "4. Restock product" << endl;
    cout << "5. Change product price" << endl;
    cout << "6. Buy product" << endl;
    cout << "7. Show shop's information" << endl;
    cout << "8. Exit" << endl;
    cout << "Choose an option: ";
}

void setupStore(string &name, string &addr, string &type, double &baseRent) {
    clearScreen();
    cout << "Enter the name of the store: ";
    getline(cin >> ws, name);
    cout << "Enter the address of the store: ";
    getline(cin >> ws, addr);
    cout << "Enter the type of the store: ";
    getline(cin >> ws, type);
    cout << "FUCK >> " << type << "\n";
    cout << "Enter the base rent of the store: ";
    cin >> baseRent;
    cout << endl;
}

void addProduct(Store *store) {
    string productName;
    double productPrice;
    int productQ;

    cout << "Enter the name of the product: ";
    getline(cin >> ws, productName);
    cout << "Enter the price of the product: ";
    cin >> productPrice;
    cout << "Enter the quantity of the product: ";
    cin >> productQ;

    try {
        store->addProduct(Product(productName, productPrice, productQ));
    } catch (invalid_argument& e) {
        cerr << e.what() << endl;
    }
    cout << "Product added successfully" << endl;
}

int main() {
    string storeName, storeAddr, storeType;
    double baseRent;
    int cmd;
    Store *store = nullptr;

    setupStore(storeName, storeAddr, storeType, baseRent);
    try {
        store = new Store(storeName, storeAddr, baseRent, storeType);
    } catch(invalid_argument& e) {
        cerr << e.what() << endl;
        return 1;
    }

    while(true) {
        clearScreen();
        printMenu();
        cin >> cmd;
        clearScreen();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (cmd) {
            case 1:
                addProduct(store);
                break;
            case 2:
                {
                    string productName;
                    cout << "Enter the name of the product: ";
                    getline(cin >> ws, productName);
                    cout << "The quantity of the product is: " << store->getProductQuantity(productName) << endl;
                }
                break;
            case 3:
                {
                    string productName;
                    cout << "Enter the name of the product: ";
                    getline(cin, productName);
                    cout << "The price of the product is: " << store->getProductPrice(productName) << endl;
                }
                break;
            case 4:
                {
                    string productName;
                    int productQ;
                    cout << "Enter the name of the product: ";
                    getline(cin, productName);
                    cout << "Enter the quantity of the product: ";
                    cin >> productQ;
                    try {
                        store->restockProduct(productName, productQ);
                    } catch (invalid_argument& e) {
                        cerr << e.what() << endl;
                    }
                    cout << "Product restocked successfully" << endl;
                }
                break;
            case 5:
                {
                    string productName;
                    double productPrice;
                    cout << "Enter the name of the product: ";
                    getline(cin, productName);
                    cout << "Enter the price of the product: ";
                    cin >> productPrice;
                    try {
                        store->changeProductPrice(productName, productPrice);
                    } catch (invalid_argument& e) {
                        cerr << e.what() << endl;
                    }
                    cout << "Product price changed successfully" << endl;
                }
                break;
            case 6:
                {
                    string productName;
                    int productQ;
                    cout << "Enter the name of the product: ";
                    getline(cin, productName);
                    cout << "Enter the quantity of the product: ";
                    cin >> productQ;
                    try {
                        store->buyProduct(productName, productQ);
                    } catch (invalid_argument& e) {
                        cerr << e.what() << endl;
                    }
                    cout << "Product bought successfully" << endl;
                }
                break;
            case 7:
                store->printStore();
                break;
            case 8:
                exit(0);
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
        cout << "Press Enter to Continue";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}