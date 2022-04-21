#include <iostream>
#include <string>
#include <vector>

#pragma once

#define SUPERMARKET 1.4
#define PHARMACY 1.3
#define NONSTOP 1.2

using namespace std;

class Property {
    private:
        string address;
        double baseRent;
        string type;

        void isValid(string address, double baseRent, string typeOfProperty);

    public:
        Property(string address, double baseRent, string typeOfProperty);
        Property(const Property &other);

        Property &operator=(const Property& other);

        ~Property();

        // Getters

        string getAddress() const;
        string getType() const;

        // Special methods

        double calcRent() const;
};