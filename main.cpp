#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
#include "TypesofUsers.h"
#include "Loan.h"

int main()
{
    //Open File for library
    std::ofstream libraryFile;
    libraryFile.open("File.txt");
    // Example usage
    std::cout << "How many books on library you want?" << std::endl;
    int librarySize;
    std::cin >> librarySize;
    Librarian librarian("John");
    Book* library = new Book[librarySize];
    libraryFile << "Books in library:" << std::endl;
    for (int i=0;i<librarySize;++i)
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
        library[i]=newBook;
        libraryFile << (i+1) << ")"<< library[i];
    }

    libraryFile << librarian;

    std::cout << "How many members would you like to add?" << std::endl;
    int kolOfMembers;
    std::cin >> kolOfMembers;
    Loan *loaners=new Loan[kolOfMembers];
    Member *members=new Member[kolOfMembers];
    libraryFile << "Members in library:" << std::endl;
    for (int i=0;i<kolOfMembers;++i)
    {
        std::string username;
        std::cout << "Enter username for member" << std::endl;
        std::cin >> username;
        Member member_for_list(username);
        members[i]=member_for_list;
        Loan loan_for_list(username,0);
        loaners[i]=loan_for_list;
        libraryFile << (i+1) << ") " << members[i];
    }

    // Librarian adds a new book
    std::cout << "Would you like to add new books to library?" << std::endl;
    std::string answer;
    std::cin >> answer;
    if (answer=="Yes")
    {
        std::cout << "How many books do you want to add?" << std::endl;
        int N;
        std::cin >> N;
        libraryFile << "Today " << N << " books was added to library." << std::endl;
        libraryFile << "Books that was added:" << std::endl;
        for (int i=0;i<N;++i) 
        {
            librarian.addBook(library, librarySize);
            libraryFile << library[librarySize-1];
        }
    }
    else
    {
        libraryFile << "Today there are no books to add." << std::endl;
    }
    
    std::cout << "Let's show the work of borrowing and returning books" << std::endl;
    std::cout << "Does somebody want to borrow book?" << std::endl;
    std::cin >> answer;
    
    if (answer=="Yes")
    {
        // Members borrow a book
        std::cout << "How many members want to borrow book?" << std::endl;
        int N;
        std::cin >> N;
        libraryFile << "There are "<< N << "books were borrowed." << std::endl;
        libraryFile << "Members which borrow books: " << std::endl;
        for (int i=0;i<N;++i)
        {
            std::cout << "Who want to borrow book from library?" <<std::endl;
            std::cout << "Enter member name" << std::endl;
            std::string name;
            std::cin >> name;
            std::cout << "Enter number of book from library(0-" << librarySize << ")" << std::endl;
            int numberOfBook;
            std::cin >> numberOfBook;
            for (int i=0;i<kolOfMembers;++i)
            {
                if (members[i].getUsername()==name)
                {
                    members[i].borrowBook(&library[numberOfBook]);
                    libraryFile << "Member " << (i+1) << " borrowed 1 book:" << std::endl << library[numberOfBook];  
                    loaners[i].addToKolOfBooks();
                    libraryFile << "Now Member " << (i+1) << " has " << loaners[i].getKolOfBooks() << " borrowing books." << std::endl;
                }
            }
        }
    }
    else
    {
        libraryFile << "Today is is no books were borrowed." << std::endl;
    }
    
    std::cout << "Does somebody want to return book?" <<std::endl;
    std::cin >> answer;
    if (answer=="Yes")
    {
        // Member returns a book
        std::cout << "How many members want to return book?" << std::endl;
        int N;
        std::cin >> N;
        libraryFile << "There are "<< N << "books were returned." << std::endl;
        libraryFile << "Members which return books: " << std::endl;
        for (int i=0;i<N;++i)
        {
            std::cout << "Who want to return book from library?" <<std::endl;
            std::cout << "Enter member name" << std::endl;
            std::string name;
            std::cin >> name;
            std::cout << "Enter number of book from library(0-" << librarySize << ")" << std::endl;
            int numberOfBook;
            std::cin >> numberOfBook;
            for (int i=0;i<kolOfMembers;++i)
            {
                if (members[i].getUsername()==name)
                {
                    members[i].returnBook(&library[numberOfBook]);
                    libraryFile << "Member " << (i+1) << " return 1 book:" << std::endl << library[numberOfBook];  
                    loaners[i].minusKolOfBooks();
                    libraryFile << "Now Member " << (i+1) << " has " << loaners[i].getKolOfBooks() << " borrowing books." << std::endl;    
                }    
            }
        }
    }
    else
    {
        libraryFile << "Today is is no books were returned." << std::endl;
    }

    std::cout << "Would you like to know information about books in library?" <<std::endl;
    std::cin >> answer;
    if (answer=="Yes")
    {
        std::cout << "Enter number of book from library(0-" << librarySize << ")" << std::endl;
        int numberOfBook;
        std::cin >> numberOfBook;
        std::cout << library[numberOfBook] << std::endl;
    }

    std::cout << "We finish the demonstration of the library's work." << std::endl;

    libraryFile << "Finish the day." << std::endl;

    // Deallocate memory for the library
    delete[] library;

    //Close File for library
    libraryFile.close();

    return 0;
}    