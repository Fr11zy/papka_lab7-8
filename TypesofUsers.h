#include <iostream>
#include "User.h"

#ifndef Member_h
#define Member_h

class Member : public User 
{
    public:
        // Constructors
        Member() : User()
        {
        }
        Member(const std::string& u) : User(u)
        {
        }

        // Destructor
        ~Member() 
        {
        }

        // Override functions for Member actions
        // Implementation of User class functions
        void borrowBook(Book* book) const override
        {
            book->borrowBook();
        }
        void returnBook(Book* book) const override
        {
            book->returnBook();
        }

        friend std::ostream& operator<<(std::ostream &out,const Member &member)
        {
            out << "Member's name is " << member.getUsername() << std::endl; 
            return out;
        }
};

#endif //Member_h

#ifndef Librarian_h
#define Librarian_h
class Librarian : public User 
{
    public:
        // Constructors
        Librarian() : User()
        {
        }
        Librarian(const std::string& u) : User(u) 
        {
        }

        // Destructor
        ~Librarian() 
        {
        }

        // Override functions for Librarian actions
        // Implementation of User class functions
        void borrowBook(Book* book) const override
        {
            book->borrowBook();
        }
        void returnBook(Book* book) const override
        {
            book->returnBook();
        }

        // Function to add a new book to the library
        void addBook(Book*& library, int& size) const 
        {
            std::string title, author, isbn;
            std::cout << "Enter book title: ";
            std::cin >> title;
            std::cout << std::endl;
            std::cout << "Enter author name: ";
            std::cin >> author;
            std::cout << std::endl;
            std::cout << "Enter ISBN: ";
            std::cin >> isbn;
            std::cout << std::endl;

            Book newBook(title, author, isbn);

            // Increase the size of the library
            size++;

            // Allocate memory for the new book
            Book* newLibrary = new Book[size];
            // Copy existing books to the new library
            for (int i = 0; i < size - 1; i++) {
                newLibrary[i] = library[i];
            }

            // Add the new book to the library
            newLibrary[size - 1] = newBook;

            // Deallocate memory for the old library
            delete[] library;

            // Update the library pointer to point to the new library
            library = newLibrary;

            std::cout << "Book added to the library successfully!\n";
        }

        friend std::ostream& operator<<(std::ostream &out,const Librarian &librarian)
        {
            out << "Librarian's name is " << librarian.getUsername() << std::endl; 
            return out;
        }
};
#endif //Librarian_h