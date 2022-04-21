#include <store/Property.hpp>

// PRIVATE

void Property::isValid(string address, double baseRent, string typeOfProperty) {
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

// PUBLIC

Property::Property(string address, double baseRent, string typeOfProperty)
: address(address), baseRent(baseRent), type(typeOfProperty) {
    isValid(address, baseRent, typeOfProperty);
}

Property::Property(const Property &other) 
: address(other.address), baseRent(other.baseRent), type(other.type) { }

Property &Property::operator=(const Property& other) {
    if(this != &other) {
        this->address = other.address;
        this->baseRent = other.baseRent;
        this->type = other.type;
    }
    return *this;
}

Property::~Property() { }

// Getters

string Property::getAddress() const { return this->address; }

string Property::getType() const { return this->type; }

// Special Getters for

double Property::calcRent() const {
    if(this->type == "supermarket")
        return this->baseRent * SUPERMARKET;
    else if(this->type == "pharmacy")
        return this->baseRent * PHARMACY;
    else if(this->type == "non-stop")
        return this->baseRent * NONSTOP;
    else
        return this->baseRent;
}