#include "include/utils/Strings_u.h"
#include <string>
#include <optional>
#include <iostream>

using namespace std;

const string default_allowed_characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


optional<string> valid_string (
    string input = "",
    int minimum_length = 0,
    int maximum_length = 5,
    string allowed_characters = default_allowed_characters,
    bool end_space = false,
    bool start_space = false

) {

    if (input.length() < minimum_length || input.length() > maximum_length) {
        return nullopt;
    }

    for (int i = 0; i < input.length(); i++) {
        if (allowed_characters.find(input[i]) == string::npos) {
            return nullopt;
        }
    }

    if (!end_space && input[input.length() - 1] == ' ') {
        return nullopt;
    }

    if (!start_space && input[0] == ' ') {
        return nullopt;
    }

    return input;
}

// TODO: Add "default_allowed_characters" in the string database
// TODO: ASCII instead of text strings