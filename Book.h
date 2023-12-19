#include <iostream>
#include <string>

#ifndef Book_h
#define Book_h

class Book 
{
    private:
        std::string title;
        std::string author;
        std::string ISBN;
        bool isAvailable;

    public:
        // Constructors
        Book() : title(""), author(""), ISBN(""),isAvailable(true) 
        {
        }
        Book(const std::string& t, const std::string& a, const std::string& isbn)
            : title(t), author(a), ISBN(isbn), isAvailable(true)
        {   
        }
        Book(const Book &other)
            : title(other.title),author(other.author),ISBN(other.ISBN),isAvailable(other.isAvailable)
        {
        }

        // Destructor
        ~Book() 
        {
        }

        // Getter methods
        std::string getTitle() const 
        { 
            return title; 
        }
        std::string getAuthor() const 
        { 
            return author;
        }
        std::string getISBN() const 
        { 
            return ISBN;
        }
        bool getAvailability() const 
        { 
            return isAvailable; 
        }

        // Overloaded operators
        // Implementation of overloaded operators
        friend std::ostream& operator<<(std::ostream& out, const Book& book)
        {
            out << "Title: " << book.title << "\nAuthor: " << book.author << "\nISBN: " << book.ISBN;
            return out;
        }

        // Overloaded functions for book search
        // Implementation of overloaded functions for book search
        void searchByTitle(const std::string& query) const
        {
            if (title.find(query) != std::string::npos)
            {
                std::cout << "Title: " << title << std::endl;
                std::cout << "Author: " << author << std::endl;
                std::cout << "ISBN: " << ISBN << std::endl;
            }
        }
        void searchByAuthor(const std::string& query) const 
        {
            if (author.find(query) != std::string::npos)
            {
                std::cout << "Title: " << title << std::endl;
                std::cout << "Author: " << author << std::endl;
                std::cout << "ISBN: " << ISBN << std::endl;
            }
        }

        void searchByISBN(const std::string& query) const 
        {
            if (ISBN.find(query) != std::string::npos)
            {
                std::cout << "Title: " << title << std::endl;
                std::cout << "Author: " << author << std::endl;
                std::cout << "ISBN: " << ISBN << std::endl;
            }
        }

        // Function to borrow a book
        // Implementation of functions for book borrowing and returning
        void borrowBook() 
        {
            if (isAvailable) 
            {
                isAvailable = false;
                std::cout << "Book borrowed successfully!\n";
            } 
            else 
            {
                std::cout << "Sorry, the book is not available for borrowing.\n";
            }
        }
        // Function to return a book
        void returnBook() 
        {
            if (!isAvailable) 
            {
                isAvailable = true;
                std::cout << "Book returned successfully!\n";
            } 
            else 
            {
                std::cout << "Error: The book is already available.\n";
            }
        }
};

#endif //Book_h