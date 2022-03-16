#include "Book.hpp"

Book::Book()
    :title(""),
    author(""),
    pageCount(0),
    isAvailable(false) {}

Book::Book(string title, string author, size_t pageCount)
    :title(title),
    author(author),
    isAvailable(true) {
    if (pageCount > 0) this->pageCount = pageCount;
}

Book::Book(const Book &other)
    :title(other.title),
    author(other.author),
    pageCount(other.pageCount),
    isAvailable(other.isAvailable) {}

Book &Book::operator=(const Book& other){
    if (this != &other){
        this->title = other.title;
        this->author = other.author;
        this->pageCount = other.pageCount;
        this->isAvailable = other.isAvailable;
    }
    return *this;
}

Book::~Book(){}

string Book::getTitle() const { 
    return this->title; 
}

string Book::getAuthor() const { 
    return this->author; 
}

size_t Book::getPageCount() const {
        return this->pageCount; 
}

void Book::printBook() const {
    cout << "Title: " << this->title << endl;
    cout << "Author: " << this->author << endl;
    cout << "Page Count: " << this->pageCount << endl;
    cout << "Is Available: " << this->isAvailable << endl;
    cout << "-----------------------------------------------------------------" << endl;
}

bool Book::isBookAvailable() const{
    return this->isAvailable;
}

void Book::changeAvailability(bool to){
    this->isAvailable = to;
}