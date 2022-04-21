#include <iostream>
#include <string>
#include <vector>

#pragma once

using namespace std;

class Product {
    private:
        string name;
        uint quantity;
        double price;

        void isValid(string name, int quantity, double price);

    public:
        Product();
        Product(string name, int quantity, double price);
        Product(const Product& other);

        Product &operator=(const Product& other);
        bool operator==(const Product& other);

        ~Product();

        // Setters

        void setQ(int quantity);
        void setPrice(double price);

        // Getters

        string getName() const;
        uint getQ() const;
        double getPrice() const;
};