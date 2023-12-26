#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av) {
    std::string str;
    if (ac < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
     for (int i = 1; i < ac; i++) {
        str = av[i];
        for (int j = 0; str[j] != '\0'; j++) {
            char Str = std::toupper(str[j]);
            std::cout << Str;
        }
    }
    std :: cout << "\n";
    return (0);
}
