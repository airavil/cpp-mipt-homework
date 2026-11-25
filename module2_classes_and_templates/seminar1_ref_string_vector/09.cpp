#include <iostream>
#include <string>

std::string repeat(int n)
{
    if (n <= 0)
        return "";
    std::string s = std::to_string(n);
    std::string result;
    for (int i = 0; i < n; ++i)
        result += s;
    return result;
}

int main()
{
    std::cout << repeat(5)  << std::endl;
    std::cout << repeat(10) << std::endl;
    std::cout << repeat(-1) << std::endl;
}