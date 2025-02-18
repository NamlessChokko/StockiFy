#pragma once 
#ifndef STRINGS_UTILS_H
#define STRINGS_UTILS_H

#include "Json_u.h"
#include "Definitions.h"
#include "Terminal_u.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


int is_valid_string (
    std::string input,
    std::string allowed_characters,
    int minimum_length,
    int maximum_length,
    bool start_space,
    bool end_space

);

std::string format(std::string input);

std::vector<std::string> adj_to_width (
    std::string input, 
    size_t width,
    bool fill,
    char empty_space
);

std::string rep_char (int times, char character);

std::string cutLine (std::string input, int width);


#endif // STRINGS_UTILS_H