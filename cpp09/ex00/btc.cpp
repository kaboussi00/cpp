#include "btc.hpp"

int aatoi(std::string str)
{
    size_t i =0;
    int sign = 1;
    int res = 0;
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
    if ((str[i] < '0' || str[i] > '9') && i < str.size())
        return -1;
    return (res * sign);
}

double sstod(const std::string& str)
{
    size_t i = 0;
    int sign = 1;
    double res = 0.0;
    double fraction = 1.0;
    
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
    if (str[i] == '.'){
        i++;
        while (str[i] >= '0' && str[i] <= '9'){
            res = res * 10 + (str[i] - '0');
            fraction *= 10;
            i++;
        }
    }
    if ((str[i] < '0' || str[i] > '9') && i < str.size())
        return -1;
    return (res * sign / fraction);
}

void my_trim_(std::string& s) {
    size_t p = s.find_first_not_of(" ");
    s.erase(0, p);
    p = s.find_last_not_of(" ");
    if (std::string::npos != p)
        s.erase(p + 1);
}

std::map<int, std::string> my_split_(const std::string& line, char delimiter) {
    std::map<int, std::string> mp;
    std::istringstream iss(line);
    std::string token;
    int index = 0;
    while (std::getline(iss, token, delimiter)) {
        mp[index++] = token;
    }
    return mp;
}

bool isValidInteger(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool isValidDouble(const std::string& str) {
    int count = 0;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i]== '.') {
            count++;
            if (count > 1)
                return false;
        } else if (str[i]< '0' || str[i]> '9') {
            return false;
        }
    }
    return true;
}

int parseInteger(const std::string& str){
    if (!isValidInteger(str))
        return (-1);
    return aatoi(str);
}

double parseDouble(const std::string& str){
    if (!isValidDouble(str))
        return (-1);
    return sstod(str);
}

bool isValidDate(int year, int month, int day) {
    if (year < 0 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (month == 2) {
        if (isLeapYear && day > 29)
            return false;
        if (!isLeapYear && day > 28)
            return false;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return false;
    }
    return true;
}

std::map<std::string, double> readDataFromFile(const std::string& filename) {
    std::map<std::string, double> data;

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::string line;
    std::getline(file, line); // Skip header line
    while (std::getline(file, line)) {
        std::map<int, std::string> tokens = my_split_(line, ',');
        std::string date = tokens[0];
        std::string value = tokens[1];
        my_trim_(date);
        my_trim_(value);
        data[date] = parseDouble(value);
    }
    return data;
}

// Calculate the value based on a date and data map
double calculateValue(const std::string& date, const std::map<std::string, double>& data) {
    std::map<std::string, double>::const_iterator it = data.upper_bound(date);
    if (it == data.begin()) {
        return 0.0;
    }
    --it;
    return it->second;
}