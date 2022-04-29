#include <iostream>
#include <vector>

using namespace std;

// Streams are objects that can be used to read and write data.
// Types of streams:
// Console
// File
// Program

// Predefined operators:
// >> - input
// << - output

class House {
    private:
        string name;
        vector<string> houseMembers;
        string address;
        double area;

    public:
        House() : name(""), address(""), area(0) { }
        House(const string &name, const vector<string> &houseMembers, const string &address, double area) 
        : name(name), houseMembers(houseMembers), address(address), area(area) {
            if(name.empty() || address.empty() || area <= 0) throw invalid_argument("Invalid args");
        }

        string getName() const { return name; }

        friend istream &operator>>(istream &in , House &h) {
            in >> h.name;
            in >> h.address;
            in >> h.area;
            return in;
        }

        friend ostream &operator<<(ostream &out, const House &h) {
            out << "=================\n";
            out << h.name << '\n';
            out << h.address << '\n';
            out << h.area << '\n';
            out << "=================\n";
            return out;
        }
};

int main() {
    House h;
    cin >> h;
    cout << h;
    return 0;
}