#include "Library.hpp"

using namespace std;

void Library::resize(){
    this->capacity = this->capacity * 2;
    Book* newBooks = new Book[this->capacity];

    for(size_t i = 0; i < this->size; ++i)
        newBooks[i] = this->books[i];
    
    delete [] this->books;
    this->books = newBooks;
}

size_t Library::getBookIndex(string title){
    for(size_t i = 0; i < this->size; ++i) 
        if(this->books[i].getTitle() == title) 
            return i;

    return -1;
}

Library::Library(size_t capacity = 2)
    :capacity(capacity),
    size(0){
    this->books = new Book[capacity];
}

Library::Library(Book* books, size_t capacity)
    : capacity(capacity),
    size(capacity){
    this->books = new Book[capacity];

    for(size_t i = 0; i < capacity; ++i)
        this->books[i] = books[i];
}

Library::Library(const Library &rhs)
    :capacity(rhs.capacity),
    size(rhs.size){
    this->books = new Book[rhs.capacity];

    for(size_t i = 0; i < rhs.size; ++i)
        this->books[i] = rhs.books[i];
}

Library &Library::operator=(const Library& rhs){
    if(this != &rhs){
        delete [] this->books;
        this->capacity = rhs.capacity;
        this->size = rhs.size;
        this->books = new Book[rhs.capacity];

        for(size_t i = 0; i < rhs.size; ++i)
            this->books[i] = rhs.books[i];
    }
    return *this;
}

Library::~Library(){
    delete [] this->books;
}

size_t Library::getBooksCount() const {
    return this->size;
}

void Library::printLibrary() const {
    for(size_t i = 0; i < this->size; ++i)
        this->books[i].printBook();
}

const Book &Library::at(size_t index) const {
    if(index <= this->size)
        return this->books[index];
}

int Library::add(const Book& book){
    for(size_t i = 0; i < this->size; ++i)
        if(this->books[i].getTitle() == book.getTitle())
            return -1;
    
    if(this->size == this->capacity)
        this->resize();
    
    this->books[this->size++] = book;
    return 0;
}

int Library::remove(string title){
    size_t indx = this->getBookIndex(title);
    if(indx == -1) return -1;

    for(size_t i = indx; i < this->size - 1; ++i)
        this->books[i] = this->books[i + 1];
   
    --this->size; 
    return 0;
}

int Library::lendBook(string title){
    size_t indx = this->getBookIndex(title);
    if(indx == -1) return -1;
    if(this->books[indx].isBookAvailable() == false) return -2;

    this->books[indx].changeAvailability(false);
    return 0;
}

int Library::returnBook(string title){
    size_t indx = this->getBookIndex(title);
    if(indx == -1) return -1;
    if(this->books[indx].isBookAvailable() == true) return -2;

    this->books[indx].changeAvailability(true);
    return 0;
}