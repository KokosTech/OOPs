#include <store/Property.hpp>
#include <store/Product.hpp>

#pragma once

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
            return 0;
        }

        uint getProductQuantity(Product product) const {
            for (size_t i = 0; i < this->products.quantity; ++i) {
                if (this->products.products[i] == product) {
                    return this->products.products[i].getQ();
                }
            }
            return 0;
        }

        double getProductPrice(string name) const {
            for (size_t i = 0; i < this->products.quantity; ++i) {
                if (this->products.products[i].getName() == name) {
                    return this->products.products[i].getPrice();
                }
            }
            return 0;
        }

        double getProductPrice(Product product) const {
            for (size_t i = 0; i < this->products.quantity; ++i) {
                if (this->products.products[i] == product) {
                    return this->products.products[i].getPrice();
                }
            }
            return 0;
        }

        // Setters

        void addProduct(string name, int quantity, double price) {
            
        }

        void addProduct(Product product) {

        }

        void restockProduct(string name, int quantity) {
            for (size_t i = 0; i < this->products.quantity; ++i) {
                if (this->products.products[i].getName() == name) {
                    this->products.products[i].setQ(this->products.products[i].getQ() + quantity);
                    return;
                }
            }
        }

        void restockProduct(Product product, int quantity) {
            for (size_t i = 0; i < this->products.quantity; ++i) {
                if (this->products.products[i].getName() == product.getName()) {
                    this->products.products[i].setQ(this->products.products[i].getQ() + quantity);
                    return;
                }
            }
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
        }


};