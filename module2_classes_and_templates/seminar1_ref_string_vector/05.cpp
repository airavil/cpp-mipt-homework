#include <iostream>
#include <string>

struct Book
{
    std::string title;
    int pages;
    float price;
};

bool isExpensive(const Book& b)
{
    return b.price > 1000;
}

int main()
{
    Book b1 = {"War and Peace", 1200, 1500};
    Book b2 = {"ABC", 20, 300};
    std::cout << isExpensive(b1) << std::endl;
    std::cout << isExpensive(b2) << std::endl;
}