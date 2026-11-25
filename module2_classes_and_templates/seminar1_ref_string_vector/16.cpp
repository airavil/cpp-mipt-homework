#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> result;
    std::size_t start = 0;
    std::size_t pos = s.find(delimiter, start);
    while (pos != std::string::npos)
    {
        result.push_back(s.substr(start, pos - start));
        start = pos + 1;
        pos = s.find(delimiter, start);
    }
    result.push_back(s.substr(start));
    return result;
}

int main()
{
    std::string data = "apple,banana,cherry,durian";
    char delimiter = ',';
    std::vector<std::string> parts = split(data, delimiter);
    for (std::size_t i = 0; i < parts.size(); ++i)
        std::cout << parts.at(i) << std::endl;
}