// Copyright 2023 Your Name <your@email.tld>

#ifndef INCLUDE_FUNCTIONS_HPP_
#define INCLUDE_FUNCTIONS_HPP_

#include <string>
#include <utility>
#include <vector>

float mean(const std::vector<float>&);
std::pair<float, float> minMax(const std::vector<float>&);
// here be argmax

void sort(std::vector<float>&);
bool remove_first_negative_element(const std::vector<int>&, int& removed_element);
std::string replace(const std::string&, const std::string&, const std::string& new_string);
std::vector<std::string> split(const std::string&, char);
std::string join(const std::vector<std::string>&, const std::string&);

#endif // INCLUDE_FUNCTIONS_HPP_
