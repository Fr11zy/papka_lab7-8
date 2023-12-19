#include <iostream>
#include <string>

#ifndef User_h
#define User_h

class User 
{
    private:
        std::string username;

    public:
        // Constructors
        User() : username("")
        {
        }
        User(const std::string& u) : username(u) 
        {
        }
        User(const User &other)
            : username(other.username)
        {
        }

        // Destructor
        ~User() 
        {
        }

        // Getter method
        std::string getUsername() const
        { 
            return username;
        }

        // Virtual functions for user actions
        virtual void borrowBook(Book* book) const = 0;
        virtual void returnBook(Book* book) const = 0;
};

#endif //User_h