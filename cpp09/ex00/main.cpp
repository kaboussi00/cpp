#include "btc.hpp"

int main(int ac, char **av){
    try{
        if (ac != 2)
        {
            std::cout << "Error: could not open file." << std::endl;
            return 0;
        }
        else{
            std::string file = av[1];
            std::ifstream infile(file);
            if (!infile.is_open()){
                std::cout<<"Error: could not open file." << std::endl;
            }
            std::string line;
            std::map<std::string, double> myMap;
            int ret = 0;
            while (std::getline(infile, line)){
                std::map<int ,std::string> split_mp_2;
                split_mp_2 = my_split_(line, '|');
                if (split_mp_2.size() != 2 || std::count(line.begin(), line.end(), '|') != 1 ){
                    std::cout << "error : Bad line format => " << line << std::endl;
                    continue ;
                }
                my_trim_(split_mp_2[0]);
                my_trim_(split_mp_2[1]);
                std::map<int ,std::string> split_mp_3;
                split_mp_3 = my_split_ (split_mp_2[0], '-');
                if (split_mp_2[1] == "value" && split_mp_2[0] == "date" && ret == 0){
                    ret += 1;
                    continue ;       
                }
                else if (split_mp_3.size() != 3 || std::count(split_mp_2[0].begin() , split_mp_2[0].end(), '-') != 2){
                    std::cout << "Error : Bad date format => " << split_mp_2[0] << std::endl;
                    continue ;
                }
                ret += 1;
                bool valid = isValidDate(aatoi(split_mp_3[0]), aatoi(split_mp_3[1]), aatoi(split_mp_3[2]));
                if (valid){
                    int parseint = parseInteger(split_mp_2[1]);
                    double parsedouble = parseDouble(split_mp_2[1]);
                    if (aatoi(split_mp_2[1]) == parseint || (sstod(split_mp_2[1]) == parsedouble))
                    {
                        if((parsedouble >= 0 && parsedouble <= 1000) || (parseint >= 0 && parseint <= 1000))
                        {
                            std::map<std::string, double> data;
                            data = readDataFromFile("data.csv");
                            double res = calculateValue(split_mp_2[0], data);
                            std::cout << split_mp_2[0] << " => " << split_mp_2[1] << " = " << res * sstod(split_mp_2[1]) << std::endl;
                        }
                        else if (parsedouble < 0 || parseint < 0){
                            std::cout << "Error : not a positive number => " << split_mp_2[1] << std::endl;
                        }
                        else{
                            std::cout << "Error : too large a number => " << split_mp_2[1] << std::endl;
                        }
                    }
                    else{
                        std::cout << "Error : Not a valid value => " << split_mp_2[1] << std::endl;
                    }
                }
                else {
                    std::cout << "Error: Not valid date => " << split_mp_2[0] << std::endl;
                }
            }
        }

    }
    catch(std::exception& ex){
        std::cout << ex.what() << std::endl;
    }
    return(0);
}
