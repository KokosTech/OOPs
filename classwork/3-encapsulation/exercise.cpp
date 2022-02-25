// Geometric figures class
// No of angles = ?

#include <iostream>
#include <cmath>

using namespace std;

class Figure{
    private:
        int sides;
        int length_of_sides;    
    public:
        Figure(){
            this->sides = 0;
            this->length_of_sides = 0;
        }

        Figure(int sides, int length_of_sides){
            this->sides = sides;
            this->length_of_sides = length_of_sides;
        }

        // Getters

        int getNoSides(){
            return this->sides;
        }

        int getLengthOfSides(){
            return this->length_of_sides;
        }

        // Setters

        void setNoSides(int sides){
            this->sides = sides;
        }

        void setLengthOfSides(int length_of_sides){
            this->length_of_sides = length_of_sides;
        }

        // Funcs

        int getParam(){
            return this->sides * this->length_of_sides;
        }

        double getArea(){
            double rad = 0;
            rad = length_of_sides / (2 * tan(M_PI / sides));
            return (getParam() / 2) * rad;
        }

        ~Figure(){}

};

int main(){
    Figure figure(4, 4);
    cout << "Param: "<< figure.getParam() << endl;
    cout << "Area: " << figure.getArea() << endl;
    return 0;
}
