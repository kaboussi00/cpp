#include "file.hpp"

void replaceString(const std::string& filename, const std::string& s1, const std::string& s2){
    std::ifstream iFile(filename);
    if (!iFile.is_open()){
        std::cout<<"Failed to open the file.";
    }
    std::string oFile = filename + ".replace";
    std::ofstream outputFile(oFile);
    if (!outputFile) {
        std::cout << "Error creating output file: " << oFile << std::endl;
        iFile.close();
        return;
    }
    std::string line;
    while (std::getline(iFile, line)) {
        std::string newLine;
        size_t begin = 0;
        size_t found = line.find(s1, begin);
        while (found != std::string::npos) {
            newLine += line.substr(begin, found - begin) + s2;
            begin = found + s1.length();
            found = line.find(s1, begin);
        }
        newLine += line.substr(begin);
        outputFile << newLine << std::endl;
    }
    if (line.empty()) {
        std::cout << "empty line" << line << std::endl;
    }
iFile.close();
outputFile.close();
}

int main(int ac, char** av) {
    if (ac < 4) {
        std::cout << " invalid argument !!" << std::endl;
        return 1;
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    if (s1.empty()){
        std::cout << "empty s1!!" << std::endl; return(0); }
    std::string s2 = av[3];

    replaceString(filename, s1, s2);

    return 0;
}
