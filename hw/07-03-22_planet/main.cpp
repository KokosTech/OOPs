#include<iostream>

using namespace std;

//============================================================================
// Homework on basic class
//============================================================================

class Planet{
    private:
        char name[50];
        double distance_to_sun;
        double diameter;
        double mass;
    public:
        Planet(const char *name, double distance_to_sun, double diameter, double mass);
        ~Planet();

        //TODO add getters and setters

        void print()const;
        double getSecondsToSun()const;
};

int main(){

    char name[50];
    cout << "Enter name of the planet: ";
    cin >> name;
    Planet p1(name, 1.0, 1.0, 1.0);
    p1.print();
    cout << "Seconds to the sun: " << p1.getSecondsToSun() << endl;

    return 0;
}

Planet::Planet(const char *name, double distance_to_sun, double diameter, double mass){
    strcpy(this->name, name);
    this->distance_to_sun = distance_to_sun > 0 ? distance_to_sun : 0;
    this->diameter = diameter > 0 ? diameter : 0;
    this->mass = mass > 0 ? mass : 0;
}

Planet::~Planet(){
    //TODO free memory
}

void Planet::print()const{
    cout << "----------------------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Distance to sun: " << distance_to_sun << endl;
    cout << "Diameter: " << diameter << endl;
    cout << "Mass: " << mass << endl;
    cout << "----------------------------------------" << endl << endl;
}

double Planet::getSecondsToSun()const{
    return this->distance_to_sun / 299792;
}