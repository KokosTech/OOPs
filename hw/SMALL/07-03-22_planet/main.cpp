#include<iostream>
#include<cstring>

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

        // setters

        void set_name(const char *name);
        void set_distance_to_sun(double distance_to_sun);
        void set_diameter(double diameter);
        void set_mass(double mass);

        // getters
        const char *get_name() const;
        double get_distance_to_sun() const;
        double get_diameter() const;
        double get_mass() const;

        void print()const;
        double getSecondsToSun()const;
};

int main(){

    char name[50];
    double distance_to_sun, diameter, mass;

    cout << "Enter name of the planet: ";
    cin >> name;
    cout << "Enter distance to the sun: ";
    cin >> distance_to_sun;
    cout << "Enter diameter: ";
    cin >> diameter;
    cout << "Enter mass: ";
    cin >> mass;

    Planet p1(name, distance_to_sun, diameter, mass);
    cout << p1.get_name() << p1.get_distance_to_sun() << p1.get_diameter() << p1.get_mass() << endl;
    p1.set_name(strcat(name, "2"));
    p1.set_mass(mass + 1);
    p1.set_diameter(diameter + 2);
    p1.set_distance_to_sun(distance_to_sun + 3);
    p1.print();
    cout << "Seconds to the sun: " << p1.getSecondsToSun() << endl;

    return 0;
}

Planet::Planet(const char *name, double distance_to_sun, double diameter, double mass){
    if(!name) return;
    if(strlen(name) >= 50) return;
    strcpy(this->name, name);
    this->distance_to_sun = distance_to_sun > 0 ? distance_to_sun : 0;
    this->diameter = diameter > 0 ? diameter : 0;
    this->mass = mass > 0 ? mass : 0;
}

Planet::~Planet(){
    //TODO free memory
}

// Setters

    void Planet::set_name(const char *name){
        if(!name) return;
        if(strlen(name) >= 50) return;
        strcpy(this->name, name);
    }

    void Planet::set_distance_to_sun(double distance_to_sun){
        this->distance_to_sun = distance_to_sun > 0 ? distance_to_sun : 0;
    }

    void Planet::set_diameter(double diameter){
        this->diameter = diameter > 0 ? diameter : 0;
    }

    void Planet::set_mass(double mass){
        this->mass = mass > 0 ? mass : 0;
    }

// Getters

    const char *Planet::get_name()const{
        return this->name;
    }

    double Planet::get_distance_to_sun()const{
        return this->distance_to_sun;
    }

    double Planet::get_diameter()const{
        return this->diameter;
    }

    double Planet::get_mass()const{
        return this->mass;
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