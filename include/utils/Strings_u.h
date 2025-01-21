#ifndef STRINGS_UTILS_H
#define STRINGS_UTILS_H

#include <string>
#include <optional>


std::optional<std::string> valid_string (
    int minimum_length,
    int maximum_length,
    std::string allowed_characters,
    bool end_space,
    bool start_space

);


#endif