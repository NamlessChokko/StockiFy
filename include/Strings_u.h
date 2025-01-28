#ifndef STRINGS_UTILS_H
#define STRINGS_UTILS_H

#include <string>
#include <optional>


std::optional<std::string> valid_string (
    std::string input,
    int minimum_length,
    int maximum_length,
    std::string allowed_characters,
    bool start_space,
    bool end_space

);


#endif