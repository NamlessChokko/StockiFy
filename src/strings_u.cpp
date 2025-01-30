#include "../include/Strings_u.h"
#include "../include/Json_u.h"
#include "../include/Definitions.h"
#include <string>

using namespace std;

const string default_file_path = "json_db/allowed_char.json";
unordered_map<string, string> colors = {
    {"*rs", rst},
    {"^bk", bk},
    {"^rd", rd},
    {"^gn", gn},
    {"^yl", yl},
    {"^bl", bl},
    {"^mg", mg},
    {"^cn", cn},
    {"^wt", wt},
    {"#bk", bg_bk},
    {"#rd", bg_rd},
    {"#gn", bg_gn},
    {"#yl", bg_yl},
    {"#bl", bg_bl},
    {"#mg", bf_mg},
    {"#cn", bf_cn},
    {"#wt", bg_wt}
};



int is_valid_string (
    string input = "",
    string key = "default_allowed_char",
    int minimum_length = 0,
    int maximum_length = 5,
    bool start_space = false,
    bool end_space = false

) {


    if (static_cast<int>(input.length()) < minimum_length || static_cast<int>(input.length()) > maximum_length) {
        return 1;
    }

    optional<string> opt_allowed_characters = get_string(default_file_path, key);

    if (!opt_allowed_characters.has_value()) {
        return 2;
    }

    string allowed_characters = opt_allowed_characters.value();

    for (int i = 0; i < static_cast<int>(input.length()); i++) {
        if (allowed_characters.find(input[i]) == string::npos) {
            return 3;
        }
    }

    if (!end_space && input[input.length() - 1] == ' ') {
        return 4;
    }

    if (!start_space && input[0] == ' ') {
        return 5;
    }

    return 0;
}

string format(string input) {
    string formatted = "";
    int key_length = 3;



    for (int i = 0; i < static_cast<int>(input.length()); i++) {
        if ((input[i] == '^' || input[i] == '#' || input[i] == '*') && (i == 0 || input[i - 1] != '\\')) {
            if (i + key_length <= static_cast<int>(input.length())) {
                string key = input.substr(i, key_length);
                if (colors.find(key) != colors.end()) {
                    formatted += colors[key];
                    i += key_length - 1;
                    continue;
                }
            }
        }
        formatted += input[i];
    }

    return formatted;
}

// TODO: implement settings to find json file path 