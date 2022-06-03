#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>

using namespace std;

class Machine {
    protected:
        string brand;
        int power; 
        int mass; // kg

        void validate() { 
            if(power <= 0) throw invalid_argument("Invalid power provided!");
            if(mass <= 0) throw invalid_argument("Invalid mass provided!");
            if(brand.empty()) throw invalid_argument("Invalid brand provided!");
        }

    public:
        Machine(string brand, int power, int mass) : brand(brand), power(power), mass(mass) {
            validate();
        }

        // copy constructor - we don't have an empty constructor, therefore valitation is not needed
        Machine(const Machine& other) : brand(other.brand), power(other.power), mass(other.mass) { } 
        Machine& operator=(const Machine& other) {
            if(this != &other) {
                brand = other.brand;
                power = other.power;
                mass = other.mass;
            }
            return *this;
        }

        double calculateTraction() const{ }
        
        //Getters
        string getBrand() const { return this->brand; }
        int getPower() const { return this->power; }
        int getMass() const { return this->mass; }
};

class Car : public Machine {
    private:
    public:
        Car(const string& brand, int power, int mass) : Machine(brand, power, mass) { }
        Car(const Car& other) : Machine(other) { }
        Car& operator=(const Car& other) {
            Machine::operator=(other);
            return *this;
        }
        double calculateTraction() const { return power * mass / 100; }


        friend ostream& operator<<(ostream& out, const Car& c) {
            out << "Brand: " << c.brand << endl;
            out << "Power: " << c.power << endl;
            out << "Mass: " << c.mass << endl;
            out << "Traction: " << c.calculateTraction() << endl;
            return out;
        }

        friend istream& operator>>(istream& in, Car& c) {
            in >> c.brand >> c.power >> c.mass;
            c.validate();
            return in;
        }
};

class Motorcycle : public Machine{
    private:
    public:
        Motorcycle(const string& brand, int power, int mass) : Machine(brand, power, mass) { }
        Motorcycle(const Motorcycle& other) : Machine(other) { }

        Motorcycle& operator=(const Motorcycle& other);

        double calculateTraction() const { return power * mass / 100; }

        friend ostream& operator<<(ostream& out, const Motorcycle& c) {
            out << "Brand: " << c.brand << endl;
            out << "Power: " << c.power << endl;
            out << "Mass: " << c.mass << endl;
            out << "Traction: " << c.calculateTraction() << endl;
            return out;
        }

        friend istream& operator>>(istream& in, Motorcycle& c) {
            in >> c.brand >> c.power >> c.mass;
            c.validate();
            return in;
        }
};

class Track {
    private:
    public: 
        static int race(const Car& car, const Motorcycle& cycle) {
            // power/mass + traction
            int carRes = car.getPower() / car.getMass() + car.calculateTraction();
            int cycleRes = cycle.getPower() / cycle.getMass() + cycle.calculateTraction();

            if(carRes > cycleRes) return -1;
            else if(carRes < cycleRes) return 1;
            else return 0;
        }
};

int main(){
    try {
        ifstream inputFile("input.txt", ios::in);
        if(!inputFile.is_open()) throw std::runtime_error("Could not open input file");

        string line;
        getline(inputFile, line);
        stringstream ss(line);

        string name = ""; int power = -1; int mass = -1;
        ss >> name >> power >> mass;

        Car car(name, power, mass);

        getline(inputFile, line);
        ss = stringstream(line);
        ss >> name >> power >> mass;
        Motorcycle cycle(name, power, mass);

        inputFile.close();

        ofstream outputFile("output.txt", ios::out);
        if(!outputFile.is_open()) throw std::runtime_error("Could not open output file");

        switch(Track::race(car, cycle)) {
            case -1:
                outputFile << car;
                break;
            case 0:
                outputFile << car;
                outputFile << cycle;
                break;
            case 1:
                outputFile << cycle;
                break;
        }

        outputFile.close();
    } catch (exception& e) {
        ofstream outputFile("output.txt", ios::out);
        if(!outputFile.is_open()) throw std::runtime_error("Could not open output file");
        outputFile << e.what();
    }
    
    return 0;
}