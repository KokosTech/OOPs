#include<iostream>

using namespace std;

// HW -> Library - more info in the classroom

class Book{
    private:
        unsigned int page_count;
        string title;
        string author;
        unsigned int price;
    public:
        // Constructors
        Book() : page_count(0), title(""), author(""), price(0) { }

        Book(unsigned int pc, string t, string a)
        :page_count(pc), title(t), author(a) { }

        Book(unsigned int pc, string t, string a, unsigned int p)
        :page_count(pc), title(t), author(a), price(p){}

        Book(const Book& rhs){
            this->page_count = rhs.page_count;
            this->title = rhs.title;
            this->author = rhs.author;
            this->price = rhs.price;
        }

        Book& operator=(const Book& rhs){
            if(this != &rhs){
                this->page_count = rhs.page_count;
                this->title = rhs.title;
                this->author = rhs.author;
                this->price = rhs.price;
            }
            return *this;
        }

        // Setters

        void set_price(unsigned int price){
            this->price = price;
        }

        // Getters

        unsigned int get_page_count()const{
            return this->page_count;
        }

        string get_title()const{
            return this->title;
        }

        string get_author()const{
            return this->author;
        }

        unsigned int get_price()const{
            return this->price;
        }

        void print()const{
            cout<<"Title: " << this->title << endl;
            cout<<"Author: " << this->author << endl;
            cout<<"Page count: " << this->page_count << endl;
            cout<<"Price: " << this->price << endl;
        }

        // Destructor

        ~Book(){}
};

int main(){
    Book b1(100, "The Communist Manifesto", "Karl Marx", 2);
    Book b2(5000, "Sweet Home", "Carnby Kim", 80);
    Book b3 = b1;
    Book b4;
    b4 = b2;

    cout << "\nBook 1\n";
    b1.print();

    cout << "\nBook 2\n";
    b2.print();
    
    cout << "\nBook 3\n";
    b3.print();
        
    cout << "\nBook 4\n";
    b4.print();
    return 0;
}
