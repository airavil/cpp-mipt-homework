#include <iostream>
#include <string>
#include <cctype>

void countLetters(const std::string& str, int& numLetters, int& numDigits)
{
    numLetters = 0;
    numDigits = 0;
    for (std::size_t i = 0; i < str.size(); ++i)
    {
        unsigned char c = str[i];
        if (std::isalpha(c))
            ++numLetters;
        else if (std::isdigit(c))
            ++numDigits;
    }
}

int main()
{
    int letters = 0, digits = 0;
    countLetters("Hello123World", letters, digits);
    std::cout << letters << " " << digits << std::endl;
}