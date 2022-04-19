#pragma once
#include <iostream>

using namespace std;

class Book{
    private:
        string title;
        string author;
        size_t pageCount;
        bool isAvailable;

    public:
        Book();
        /**
         * @brief Construct a new Book object
         * 
         * @param title 
         * @param author 
         * @param pageCount 
         */
        Book(string title, string author, size_t pageCount);

        /**
         * @brief Copy constructor for a new Book object
         * 
         * @param other 
         */
        Book(const Book& other);
        /**
         * @brief Destroy the Book object
         * 
         */
        ~Book();

        Book& operator=(const Book& other);
        /**
         * @brief Get the Title object
         * 
         * @return string 
         */
        string getTitle() const;

        /**
         * @brief Get the Author object
         * 
         * @return string 
         */
        string getAuthor() const;

        /**
         * @brief Get the Page Count object
         * 
         * @return size_t 
         */
        size_t getPageCount() const;

        void printBook() const;

        bool isBookAvailable() const;

        void changeAvailability(bool to);
};
