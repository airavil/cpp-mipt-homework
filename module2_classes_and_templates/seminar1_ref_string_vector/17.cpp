#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::vector<std::size_t>> calculate_word_lengths(const std::string& filename)
{
    std::vector<std::vector<std::size_t>> result;
    std::ifstream in(filename);
    if (!in.is_open())
        return result;

    std::string line;
    while (std::getline(in, line))
    {
        std::vector<std::size_t> lengths;
        std::size_t i = 0;
        while (i < line.size())
        {
            while (i < line.size() && std::isspace(line[i]))
                ++i;
            std::size_t start = i;
            while (i < line.size() && !std::isspace(line[i]))
                ++i;
            if (i > start)
                lengths.push_back(i - start);
        }
        result.push_back(lengths);
    }
    return result;
}

int main()
{
    std::vector<std::vector<std::size_t>> v = calculate_word_lengths("input.txt");
    for (std::size_t i = 0; i < v.size(); ++i)
    {
        for (std::size_t j = 0; j < v[i].size(); ++j)
            std::cout << v[i][j] << " ";
        std::cout << std::endl;
    }
}