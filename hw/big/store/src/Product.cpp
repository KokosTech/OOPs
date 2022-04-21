#include "store/Product.hpp"

void Product::isValid(string name, int quantity, double price) {
    if (name.empty()) 
        throw invalid_argument("Name cannot be empty");
    if (quantity < 0) 
        throw invalid_argument("Quantity cannot be negative");
    if (price < 0) 
        throw invalid_argument("Price cannot be negative");
}

Product::Product() {
    this->name = "";
    this->quantity = 0;
    this->price = 0;
}

Product::Product(string name, int quantity, double price) 
: name(name), quantity(quantity), price(price) {
    isValid(name, quantity, price);
}

Product::Product(const Product& other) {
    this->name = other.name;
    this->quantity = other.quantity;
    this->price = other.price;
}

Product &Product::operator=(const Product& other) {
    if(this != &other) {
        this->name = other.name;
        this->quantity = other.quantity;
        this->price = other.price;
    }
    return *this;
}

bool Product::operator==(const Product& other) {
    return this->name == other.name && this->quantity == other.quantity && this->price == other.price;
}

Product::~Product() {}

// Setters

void Product::setQ(int quantity) {
    if(quantity < 0)
        throw invalid_argument("Quantity cannot be negative");
    else 
        this->quantity = quantity;
}

void Product::setPrice(double price) {
    if(price < 0)
        throw invalid_argument("Price cannot be negative");
    else 
        this->price = price;
}

string Product::getName() const { return this->name; }
uint Product::getQ() const { return this->quantity; }
double Product::getPrice() const { return this->price; }