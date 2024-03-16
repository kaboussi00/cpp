#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <stdexcept>

int                             aatoi(std::string str);
double                          sstod(const std::string& str);
void                            my_trim_(std::string& s);
std::map<int, std::string>      my_split_(const std::string& line, char delimiter);
bool                            isValidInteger(const std::string& str);
bool                            isValidDouble(const std::string& str);
int                             parseInteger(const std::string& str);
double                          parseDouble(const std::string& str);
bool                            isValidDate(int year, int month, int day);
std::map<std::string, double>   readDataFromFile(const std::string& filename);
double                          calculateValue(const std::string& date, const std::map<std::string, double>& data);