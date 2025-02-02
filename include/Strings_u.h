#pragma once 
#ifndef STRINGS_UTILS_H
#define STRINGS_UTILS_H

#include <string>
#include <vector>


int is_valid_string (
    std::string input,
    std::string allowed_characters,
    int minimum_length,
    int maximum_length,
    bool start_space,
    bool end_space

);

std::string format(std::string input);

std::vector<std::string> adj_to_width (std::string input);


#endif // STRINGS_UTILS_H