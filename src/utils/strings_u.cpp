#include "../../include/Strings_u.h"
#include "../../include/Json_u.h"
#include "../../include/Definitions.h"
#include "../../include/Terminal_u.h"
#include <string>

using namespace std;

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


    if (static_cast<int>(input.length()) < minimum_length) {
        return 309;
    }

    if (static_cast<int>(input.length()) > maximum_length) {
        return 310;
    }

    string allowed_characters = get_string(key, "json_db/allowed_characters.json");

    if (allowed_characters == "error") {
        return 304;
    }

    for (int i = 0; i < static_cast<int>(input.length()); i++) {
        if (allowed_characters.find(input[i]) == string::npos) {
            if (allowed_characters.find(input[i]) == ' ') {
                return 308;
            }
            return 305;
        }
    }

    if (!end_space && input[input.length() - 1] == ' ') {
        return 306;
    }

    if (!start_space && input[0] == ' ') {
        return 307;
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

vector<string> adj_to_width (string input, int width) {
    vector<string> lines; 
    int input_length = static_cast<int>(input.length());
    int last_space = 0;
    char empty_space = ' ';

    for (int i = 0; i < input_length; i++) {

        if (input_length <= width) { // if the input length is less than the width, add the input to the lines vector and break the loop
            lines.push_back(input);
            break;
        } else {
            if (input_length == 0) { // if the input length is 0, break the loop
                break;
            }
        }

        
        if (input[i] == empty_space) { // if the current character is a space, save the index
            last_space = i;
        }

        if (i >= width && last_space == 0) { // if the current index is equal to the width and the last space is 0
            lines.push_back(input.substr(0, width - 1)); // add the substring from the beginning to the width to the lines vector
            input = input.substr(width - 1); // set the input to the substring from the width to the end
            i = 0;
            input_length = static_cast<int>(input.length()); // set the input length to the length of the new input
            last_space = 0;
        }

        if (i == width && last_space < width){ // if the current index is equal to the width and the last space is less than the width
            lines.push_back(input.substr(0, last_space)); // add the substring from the beginning to the last space to the lines vector
            input = input.substr(last_space + 1); // set the input to the substring from the last space to the end
            i = 0;
            input_length = static_cast<int>(input.length()); // set the input length to the length of the new input
            last_space = 0;
        }

        

    }

    return lines; // return the lines vector
}


// TODO: Fix adj_to_width function to handle multiple spaces between long words
// TODO: implement settings to find json file path 