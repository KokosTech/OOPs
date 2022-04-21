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

        void isValid(string name);
        void resize();
        bool repetative(string name);

    public:
        Store(string name, string address, double rent, string typeOfProperty);
        Store(const Store& other);

        Store &operator=(const Store& other);

        ~Store();

        // Getters

        string getName() const;

        // Special getters
        products_t *revision_old() const;
        vector<Product> revision() const;

        uint getProductQuantity(string name) const;
        uint getProductQuantity(Product product) const;

        double getProductPrice(string name) const;
        double getProductPrice(Product product) const;

        void printStore() const;

        // Setters

        void addProduct(string name, int quantity, double price);
        void addProduct(Product product);

        void restockProduct(string name, int quantity);
        void restockProduct(Product product, int quantity);

        void buyProduct(string name, int quantityToBuy);
        void buyProduct(Product product, int quantityToBuy);

        void changeProductPrice(string name, double price);
        void changeProductPrice(Product product, double price);
};