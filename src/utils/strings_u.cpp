#include "include/utils/Strings_u.h"
#include "../../include/utils/Json_U.h"
#include <string>
#include <optional>
#include <iostream>

using namespace std;

const string default_file_path = "../../json_db/strings_db.json";



optional<string> valid_string (
    string input = "",
    int minimum_length = 0,
    int maximum_length = 5,
    string key = "default_allowed_char",
    bool end_space = false,
    bool start_space = false

) {

    if (input.length() < minimum_length || input.length() > maximum_length) {
        return nullopt;
    }

    optional<string> opt_allowed_characters = get_string(key, default_file_path);
    string allowed_characters;

    if (!opt_allowed_characters.has_value()) {
        return nullopt;
    }

    allowed_characters = opt_allowed_characters.value();

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

// TODO: implement settings to find json file path 