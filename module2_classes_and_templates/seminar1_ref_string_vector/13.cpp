#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<std::string>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

std::vector<std::string> prefixes(const std::string& s)
{
    std::vector<std::string> result;
    for (std::size_t i = 1; i <= s.size(); ++i)
        result.push_back(s.substr(0, i));
    return result;
}

int main()
{
    std::vector<std::string> v = prefixes("Mouse");
    print(v);
}