#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>
#include <algorithm>

long long           aatoi(std::string str);
int                 check_number(const std::string& str);
std::vector<int>    split(const std::string& line, char delimiter);
void                swap_pair(std::pair<int, int>& a, std::pair<int, int>& b);
std::vector<int>    sort_vector(std::vector<int> vec);
std::deque<int>     sort_deque(std::deque<int> vec);