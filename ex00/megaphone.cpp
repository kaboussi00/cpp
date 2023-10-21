#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av) {
    std::string str;
    if (ac < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
     for (int i = 1; i < ac; i++) {
        str = av[i];
        for (int j = 0; str[j] != '\0'; j++) {
            char upperStr = std::toupper(av[i][j]);
            std::cout << upperStr;
        }
    }
    std :: cout << "\n";
    return (0);
}
