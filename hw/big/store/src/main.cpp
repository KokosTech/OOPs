#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <exception>

#include <store/Product.hpp>
#include <store/Property.hpp>
#include <store/Store.hpp>

using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void printMenu() {
    clearScreen();
    cout << "======== MENU ========" << endl;
    cout << "1. Add а product" << endl;
    cout << "2. Check product quantity" << endl;
    cout << "3. Check product price" << endl;
    cout << "4. Restock а product" << endl;
    cout << "5. Change product price" << endl;
    cout << "6. Buy а product" << endl;
    cout << "7. Show shop's information" << endl;
    cout << "8. Show products with limited stock" << endl;
    cout << "9. Exit" << endl;
    cout << "10. [LEGACY] non-STL version of revision() -> Show products with limited stock" << endl;
    cout << "======================" << endl;
    cout << "Choose an option: ";
}

void setupStore(string &name, string &addr, string &type, double &baseRent) {
    clearScreen();
    cout << "Enter the name of the store: ";
    getline(cin, name);
    cout << "Enter the address of the store: ";
    getline(cin , addr);
    cout << "Enter the type of the store: ";
    getline(cin , type);
    cout << "Enter the base rent of the store: ";
    cin >> baseRent;
    cout << endl;
}

void addProduct(Store *store) {
    string productName;
    double productPrice;
    int productQ;

    cout << "Enter the name of the product: ";
    getline(cin , productName);
    cout << "Enter the price of the product: ";
    cin >> productPrice;
    cout << "Enter the quantity of the product: ";
    cin >> productQ;

    try {
        store->addProduct(Product(productName, productQ, productPrice));
    } catch (invalid_argument& e) {
        cerr << e.what() << endl;
        return;
    }
    cout << productName << " added successfully" << endl;
}

void checkProductQuantity(Store *const store) {
    string productName;
    cout << "Enter the name of the product: ";
    getline(cin , productName);
    try {
        cout << "The quantity of the product " << productName << " is " << store->getProductQuantity(productName) << endl;    
    } catch (invalid_argument& e) {
        cerr << e.what() << endl;
    }
}

void checkProductPrice(Store *const store) {
    string productName;
    cout << "Enter the name of the product: ";
    getline(cin , productName);
    try {
        cout << "The price of the product " << productName << " is " << store->getProductPrice(productName) << endl;    
    } catch (invalid_argument& e) {
        cerr << e.what() << endl;
        return;
    }
}

void restockProduct(Store *store) {
    string productName;
    int productQ;
    cout << "Enter the name of the product: ";
    getline(cin , productName);
    cout << "Enter the quantity of the product: ";
    cin >> productQ;
    try {
        store->restockProduct(productName, productQ);
    } catch (invalid_argument& e) {
        cerr << e.what() << endl;
        return;
    }
    cout << productName << " has been restocked successfully" << endl;
}

void changeProductPrice(Store *store) {
    string productName;
    double productPrice;

    cout << "Enter the name of the product: ";
    getline(cin, productName);
    cout << "Enter the price of the product: ";
    cin >> productPrice;

    try {
        store->changeProductPrice(productName, productPrice);
    } catch (invalid_argument& e) {
        return;
        cerr << e.what() << endl;
    }

    cout << productName << " price changed successfully" << endl;
}

void buyProduct(Store *store) {
    string productName;
    int productQ;

    cout << "Enter the name of the product: ";
    getline(cin , productName);
    cout << "Enter the quantity of the product: ";
    cin >> productQ;

    try {
        store->buyProduct(productName, productQ);
    } catch (invalid_argument& e) {
        cerr << e.what() << endl;
        return;
    }

    cout << productName << " has been bought successfully" << endl;
}

void revision(Store *const store) {
    vector<Product> v = store->revision();
    for (int i = 0; i < v.size(); ++i) {
            cout << "===" << v[i].getName() << "===" << endl;
            cout << "Quantity: " << v[i].getQ() << endl;
            cout << "Price: " << v[i].getPrice() << endl;
    }
}

void revision_old(Store *const store) {
    products_t *v = store->revision_old();
    for (int i = 0; i < v->quantity; ++i) {
            cout << "===" << v->products[i].getName() << "===" << endl;
            cout << "Quantity: " << v->products[i].getQ() << endl;
            cout << "Price: " << v->products[i].getPrice() << endl;
    }
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
        printMenu();
        cin >> cmd;
        clearScreen();

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (cmd) {
            case 1:
                addProduct(store);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 2:
                checkProductQuantity(store);
                break;
            case 3:
                checkProductPrice(store);
                break;
            case 4:
                restockProduct(store);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 5:
                changeProductPrice(store);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 6:
                buyProduct(store);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 7:
                store->printStore();
                break;
            case 8:
                revision(store);
                break;
            case 9:
                exit(0);
                break;
            case 10:
                revision_old(store);
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