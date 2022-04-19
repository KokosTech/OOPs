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

        void isValid(string name, int quantity, double price) {
            if (name.empty()) 
                throw invalid_argument("Name cannot be empty");
            if (quantity < 0) 
                throw invalid_argument("Quantity cannot be negative");
            if (price < 0) 
                throw invalid_argument("Price cannot be negative");
        }

    public:
        Product() {
            this->name = "";
            this->quantity = 0;
            this->price = 0;
        }

        Product(string name, int quantity, double price) 
        : name(name), quantity(quantity), price(price) {
            isValid(name, quantity, price);
        }

        Product(const Product& other) {
            this->name = other.name;
            this->quantity = other.quantity;
            this->price = other.price;
        }

        Product &operator=(const Product& other) {
            if(this != &other) {
                this->name = other.name;
                this->quantity = other.quantity;
                this->price = other.price;
            }
            return *this;
        }

        bool operator==(const Product& other) {
            return this->name == other.name && this->quantity == other.quantity && this->price == other.price;
        }


        ~Product() {}

        // Setters

        void setQ(int quantity) {
            try {
                if(quantity < 0)
                    throw invalid_argument("Quantity cannot be negative");
                else 
                    this->quantity = quantity;
            } catch(invalid_argument& e) {
                cerr << e.what() << endl;
            }
        }

        void setPrice(double price) {
            try {
                if(price < 0)
                    throw invalid_argument("Price cannot be negative");
                else 
                    this->price = price;
            } catch(invalid_argument& e) {
                cerr << e.what() << endl;
            }
        }

        // Getters

        string getName()const { return this->name; }
        uint getQ()const { return quantity; }
        double getPrice()const { return this->price; }
};