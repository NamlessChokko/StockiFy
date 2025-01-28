#include "../include/Strings_u.h"
#include "../include/Json_U.h"
#include <string>
#include <optional>
#include <iostream>

using namespace std;

const string default_file_path = "json_db/allowed_char.json";



bool is_valid_string (
    string input = "",
    string key = "default_allowed_char",
    int minimum_length = 0,
    int maximum_length = 5,
    bool start_space = false,
    bool end_space = false

) {


    if (static_cast<int>(input.length()) < minimum_length || static_cast<int>(input.length()) > maximum_length) {
        return false;
    }

    optional<string> opt_allowed_characters = get_string(default_file_path, key);

    if (!opt_allowed_characters.has_value()) {
        return false;
    }

    string allowed_characters = opt_allowed_characters.value();

    for (int i = 0; i < static_cast<int>(input.length()); i++) {
        if (allowed_characters.find(input[i]) == string::npos) {
            return false;
        }
    }

    if (!end_space && input[input.length() - 1] == ' ') {
        return false;
    }

    if (!start_space && input[0] == ' ') {
        return false;
    }

    return true;
}

// TODO: implement settings to find json file path 