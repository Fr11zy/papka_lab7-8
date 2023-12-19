#include <iostream>
#include <string>

class Loan
{
    private:
        std::string loanname;
        int kolOfBooks;
    public:
        Loan() : loanname(""),kolOfBooks(0)
        {
        }
        Loan(const std::string &l, const int &k)
            : loanname(l),kolOfBooks(k)
        {
        }
        Loan(const Loan &other)
            :loanname(other.loanname), kolOfBooks(other.kolOfBooks)
        {
        }

        void addToKolOfBooks()
        {
            this->kolOfBooks=(kolOfBooks+1);
        }

        void minusKolOfBooks()
        {
            this->kolOfBooks=(kolOfBooks-1);
        }
        std::string getLoanname() const
        {
            return loanname;
        }

        int getKolOfBooks() const
        {
            return kolOfBooks;
        }
};
