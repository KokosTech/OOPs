#pragma once
#include <iostream>
#include "Book.hpp"

using namespace std;

class Library{

    //Array of books, books count, array size, capacity
    Book* books;
    size_t size, capacity;

    /**
     * @brief Resizing the array with double capacity. Resize is private method because it is used only by the addition of the book
     * 
     */
    void resize();
    size_t getBookIndex(string title);
public:
    /**
     * @brief Construct a new Library object. Creating empty library with the booksCount as capacity
     * 
     * @param booksCount 
     */
    Library(size_t capacity);

    /**
     * @brief Construct a new Library object. Creating library with books count as capacity and copying the Book objects from books
     * 
     * @param books 
     * @param booksCount 
     */
    Library(Book* books, size_t size);

    /**
     * @brief Construct a new Library object. Copy constructor
     * 
     * @param rhs 
     */
    Library(const Library &rhs);


    /**
     * @brief Assign operator overloading
     * 
     * @param rhs 
     * @return Library& 
     */
    Library &operator=(const Library& rhs); //Write it if you want it is almost the same as the copy constructor

    /**
     * @brief Get the Books Count
     * 
     * @return size_t 
     */

    ~Library();

    size_t getBooksCount() const;
    
    void printLibrary() const;

    /**
     * @brief Get a book at the provided index. Validate the index
     * 
     * @param index 
     * @return const Book& 
     */
    const Book &at(size_t index) const;

    /**
     * @brief Adding a Book to a Library. Check if a Book with this name already exists in the library if so return -1, else return 0.
     * 
     * @param book 
     */
    int add(const Book& book);

    /**
     * @brief Remove a book from the array. Return -1 if not found, else return 0
     * 
     * @param title 
     * @return int 
     */
    int remove(string title);

    /**
     * @brief Change the isAvailable field of the book. Aka lending the book. Validate if the book is available
     * 
     * @param title 
     * @return int 
     */
    int lendBook(string title);

    /**
     * @brief Change the isAvailable field of the book. Aka returning a landed book. Make a validation if this book has been lended
     * 
     * @param title 
     */
    int returnBook(string title);
};