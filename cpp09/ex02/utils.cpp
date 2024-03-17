#include "sort.hpp"

long long aatoi(std::string str)
{
    int i =0;
    int sign = 1;
    long long res = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == '-'){
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9'){
        res = res * 10 + (str[i] - '0');
        i++;
    }
    if (res > 2147483647 || res < -2147483648)
        throw std::invalid_argument("out of range");
    return (res * sign);
}

int check_number(const std::string& str)
{
    for (size_t i = 0; i < str.size() ; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            throw std::invalid_argument("Not a number");
    }
    return aatoi(str);
}

std::vector<int> split(const std::string& line, char delimiter)
{
    std::vector<int> result;
    size_t start = 0;
    size_t end = line.find(delimiter, start);

    while (end != std::string::npos)
    {
        std::string substr = line.substr(start, end - start);
        result.push_back(check_number(std::string(substr)));

        start = end + 1;
        end = line.find(delimiter, start);
    }

    std::string substr = line.substr(start);
    result.push_back(check_number(std::string(substr)));

    return result;
}

void swap_pair(std::pair<int, int>& a, std::pair<int, int>& b){
    std::pair<int, int> tmp;
    tmp = a;
    a = b;
    b = tmp;
}