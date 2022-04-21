#include <store/Property.hpp>
#include <store/Product.hpp>

#pragma once

// TODO - Fix TRY CATCH FOR ----> getQ and getPrice

#define D_CAP 2

using namespace std;

typedef struct products {
    Product *products;
    size_t quantity;
    size_t capacity;
} products_t;

class Store : public Property {
    private:
        string name;
        products_t products;

        void isValid(string name) {
            if (name.empty())
                throw std::invalid_argument("Name cannot be empty");
        }

        void resize() {
            Product *tmp = new Product[this->products.capacity * 2];
            for (size_t i = 0; i < this->products.capacity; i++) {
                tmp[i] = this->products.products[i];
            }
            delete[] this->products.products;
            this->products.capacity *= 2;
            this->products.products = tmp;
            
        }

        bool repetative(string name) {
            for (size_t i = 0; i < products.quantity; i++) {
                if (products.products[i].getName() == name)
                    return true;
            }
            return false;
        }

    public:
        Store(string name, string address, double rent, string typeOfProperty) : Property(address, rent, typeOfProperty) {
            this->name = name;
            this->products.quantity = 0;
            this->products.capacity = D_CAP;
            this->products.products = new Product[this->products.capacity];
        }

        Store(const Store& other) : Property(other) {
            this->name = other.name;
            this->products.capacity = other.products.capacity;
            this->products.products = new Product[this->products.capacity];
            for (size_t i = 0; i < this->products.capacity; i++) {
                this->products.products[i] = other.products.products[i];
            }
        }

        Store &operator=(const Store& other) {
            if(this != &other) {
                Property::operator=(other);
                this->name = other.name;
                this->products.capacity = other.products.capacity;
                this->products.products = new Product[this->products.capacity];
                for (size_t i = 0; i < this->products.capacity; i++) {
                    this->products.products[i] = other.products.products[i];
                }
            }
            return *this;
        }

        ~Store() {
            delete[] this->products.products;
        }

        // Getters

        string getName()const {
            return this->name;
        }

/*         products_t *revision()const {
            products_t *products = new products_t;
            products->
            return &this->products;
        } */

        vector<Product> revision() const { 
            vector<Product> v;
            for(int i = 0; i < this->products.quantity; ++i) {
                if(this->products.products[i].getQ() < 5) {
                    v.push_back(this->products.products[i]);
                }
            }

            return v;
        }

        uint getProductQuantity(string name) const {
            for (size_t i = 0; i < this->products.quantity; ++i) {
                if (this->products.products[i].getName() == name) {
                    return this->products.products[i].getQ();
                }
            }
            throw invalid_argument("Product does not exist!");
        }

        uint getProductQuantity(Product product) const {
            for (size_t i = 0; i < this->products.quantity; ++i) {
                if (this->products.products[i] == product) {
                    return this->products.products[i].getQ();
                }
            }
            throw invalid_argument("Product does not exist!");
        }

        double getProductPrice(string name) const {
            for (size_t i = 0; i < this->products.quantity; ++i) {
                if (this->products.products[i].getName() == name) {
                    return this->products.products[i].getPrice();
                }
            }
            throw invalid_argument("Product does not exist!");
        }

        double getProductPrice(Product product) const {
            for (size_t i = 0; i < this->products.quantity; ++i) {
                if (this->products.products[i] == product) {
                    return this->products.products[i].getPrice();
                }
            }
            throw invalid_argument("Product does not exist!");
        }

        void printStore()const {
            cout << "Store name: " << this->name << endl;
            cout << "Address: " << this->getAddress() << endl;
            cout << "Rent: " << this->calcRent() << endl;
            cout << "Type of property: " << this->getType() << endl;
            
            if(this->products.quantity > 0) {
                cout << "Products: " << endl;
                for (size_t i = 0; i < this->products.quantity; i++) {
                    cout << "===" << this->products.products[i].getName() << "===" << endl;
                    cout << "Quantity: " << this->products.products[i].getQ() << endl;
                    cout << "Price: " << this->products.products[i].getPrice() << endl;
                }
            }
        } 

        // Setters

        void addProduct(string name, int quantity, double price) {
            if (this->repetative(name)) {
                throw std::invalid_argument("Product already exists");
            }
            if (this->products.quantity == this->products.capacity) {
                this->resize();
            }
            this->products.products[this->products.quantity++] = Product(name, quantity, price);
        }

        void addProduct(Product product) {
            if (this->repetative(product.getName())) {
                throw std::invalid_argument("Product already exists");
            }
            if (this->products.quantity == this->products.capacity) {
                this->resize();
            }
            this->products.products[this->products.quantity++] = product;
        }

        void restockProduct(string name, int quantity) {
            for (size_t i = 0; i < this->products.quantity; ++i) {
                if (this->products.products[i].getName() == name) {
                    this->products.products[i].setQ(this->products.products[i].getQ() + quantity);
                    return;
                }
            }
                        throw invalid_argument("Product does not exist!");

        }

        void restockProduct(Product product, int quantity) {
            for (size_t i = 0; i < this->products.quantity; ++i) {
                if (this->products.products[i].getName() == product.getName()) {
                    this->products.products[i].setQ(this->products.products[i].getQ() + quantity);
                    return;
                }
            }
                        throw invalid_argument("Product does not exist!");

        }

        void buyProduct(string name, int quantityToBuy) {
            for (size_t i = 0; i < this->products.quantity; ++i) {
                if (this->products.products[i].getName() == name) {
                    if (this->products.products[i].getQ() >= quantityToBuy) {
                        (this->products.products[i].getQ() > quantityToBuy) ? this->products.products[i].setQ(this->products.products[i].getQ() - quantityToBuy) : this->products.products[i].setQ(0);
                        return;
                    }
                }
            }
                        throw invalid_argument("Product does not exist!");

        }

        void changeProductPrice(string name, double price) {
            if (price < 0) {
                throw std::invalid_argument("Price can't be negative");
            }
            for (size_t i = 0; i < this->products.quantity; ++i) {
                if (this->products.products[i].getName() == name) {
                    this->products.products[i].setPrice(price);
                    return;
                }
            }
                        throw invalid_argument("Product does not exist!");

        }

        void changeProductPrice(Product product, double price) {
            if (price < 0) {
                throw std::invalid_argument("Price can't be negative");
            }
            for (size_t i = 0; i < this->products.quantity; ++i) {
                if (this->products.products[i] == product) {
                    this->products.products[i].setPrice(price);
                    return;
                }
            }
                        throw invalid_argument("Product does not exist!");

        }
};