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

string find_error_message(const json& j, const string& key) {
    if (j.is_object()) { 
        for (auto& [category, errors] : j.items()) {
            if (errors.is_object()) {  
                auto it = errors.find(key);
                if (it != errors.end()) {
                    return it.value();  
                }
            }
        }
    }
    return "";
}

string read_error_message(int error_number, string file_path = default_file_path) {
    json json_file;
    string key = to_string(error_number);

    try {
        ifstream file(file_path);
        if (!file) {
            return "An unexpected error occurred. Please, check directory json_db/expected_errors.json. Error: Unable to open error message file.";
        }

        file >> json_file;
        file.close();
    } catch (json::parse_error& e) {
        return "An unexpected error occurred. Please, check directory json_db/expected_errors.json. Error: Unable to open error message file.";
    }

    string message = find_error_message(json_file, key);
    if (!message.empty()) {
        return message;
    }

    return "An unexpected error occurred. Please, check directory json_db/expected_errors.json";
}