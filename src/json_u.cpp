#include "../lib/nlohmann/json.hpp"
#include "../include/Json_u.h"
#include <string>
#include <optional>
#include <iostream>
#include <fstream>

using namespace std;
using namespace nlohmann;
const string default_char_in_case_of_error = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
const string default_file_path = "json_db/expected_errors.json";
const string default_file_path = "json_db/expected_errors.json";


string get_string(string key, string file_path = default_file_path) {
    json json_file;

    try {
        ifstream file(file_path);
        file >> json_file;
        file.close();
    } catch (json::parse_error& e) {
        return default_char_in_case_of_error;
    }

    if (json_file.find(key) == json_file.end()) {
        return default_char_in_case_of_error;
    }

    return json_file[key];
}

string read_error_message(int error_number, string file_path = default_file_path) {
    string error_type = "";
    json json_file;
    string key = to_string(error_number); 

    try {
        ifstream file(file_path);
        file >> json_file;
        file.close();
    } catch (json::parse_error& e) {;
        return "An unexpected error occurred. Please, check directory json_db/expected_errors.json";
    }



    for (auto& error_type : json_file.items()) {
        if (error_type.key() == key) {
            return error_type.value();
        }
    }

    return "An unexpected error occurred. Please, check directory json_db/expected_errors.json";
}
