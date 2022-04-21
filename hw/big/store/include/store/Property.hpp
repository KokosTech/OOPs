#include <iostream>
#include <string>
#include <vector>

#pragma once

using namespace std;

class Property {
    private:
        string address;
        double baseRent;
        string type;

        void isValid(string address, double baseRent, string typeOfProperty) {
            if (address.empty())
                throw std::invalid_argument("Address cannot be empty");

            if (baseRent < 0)
                throw std::invalid_argument("Rent cannot be negative");

            /* if ( 
                typeOfProperty != "supermarket" && 
                typeOfProperty != "pharmacy" && 
                typeOfProperty != "non-stop" && 
                typeOfProperty != "other"
            ) throw invalid_argument("Type of property cannot be " + ((typeOfProperty.empty()) ? "empty" : ("\"" + typeOfProperty + "\""))); */
            
            if ( 
                typeOfProperty != "supermarket" && 
                typeOfProperty != "pharmacy" && 
                typeOfProperty != "non-stop"
            ) this->type = "other";
        }

    public:
        Property(string address, double baseRent, string typeOfProperty) {
            this->address = address;
            this->baseRent = baseRent;
            this->type = typeOfProperty;
            isValid(address, baseRent, typeOfProperty);
        }

        Property(const Property& other) {
            this->address = other.address;
            this->baseRent = other.baseRent;
            this->type = other.type;
        }

        Property &operator=(const Property& other) {
            if(this != &other) {
                this->address = other.address;
                this->baseRent = other.baseRent;
                this->type = other.type;
            }
            return *this;
        }

        ~Property() {}

        // Setters

       /*  void setAddress(string address) {
            try {
                if(address.empty())
                    throw std::invalid_argument("Address cannot be empty");
                else 
                    this->address = address;
            } catch(std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
        }

        void setRent(double rent) {
            try {
                if(rent < 0)
                    throw std::invalid_argument("Rent cannot be negative");
                else 
                    this->rent = rent;
            } catch(std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
        }

        void setTypeOfProperty(string typeOfProperty) {
            try {
                if(typeOfProperty.empty() && (
                        typeOfProperty != "supermarket" || 
                        typeOfProperty != "pharmacy" || 
                        typeOfProperty != "non-stop" || 
                        typeOfProperty != "other"
                    )
                ) throw invalid_argument("Type of property cannot be empty");
                else 
                    this->typeOfProperty = typeOfProperty;
            } catch(std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
        }
 */
        // Getters

        string getAddress()const {
            return this->address;
        }

        string getTypeOfProperty()const {
            return this->type;
        }

        // Special methods

        double calcRent()const {
            if(this->type == "supermarket")
                return this->baseRent * 1.4;
            else if(this->type == "pharmacy")
                return this->baseRent * 1.3;
            else if(this->type == "non-stop")
                return this->baseRent * 1.2;
            else
                return this->baseRent;
        }

};