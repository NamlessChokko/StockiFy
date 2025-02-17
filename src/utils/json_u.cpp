#include "../../lib/nlohmann/json.hpp"
#include "../../include/Json_u.h"
#include <string>
#include <optional>
#include <iostream>
#include <fstream>

using namespace std;
using namespace nlohmann;


string get_string(string key, string file_path) {
    json json_file;

    try {
        ifstream file(file_path);
        file >> json_file;
        file.close();
    } catch (json::parse_error& e) {
        return "error";
    }

    if (json_file.find(key) == json_file.end()) {
        return "error";
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

string read_error_message(int error_number, string file_path) {
    json json_file;
    string key = to_string(error_number);

    try {
        ifstream file(file_path);
        if (!file) {
            return "An unexpected error occurred. Please, check directory Skfy_settings/expected_errors.json.";
        }

        file >> json_file;
        file.close();
    } catch (json::parse_error& e) {
        return "An unexpected error occurred. Please, check directory Skfy_settings/expected_errors.json.";
    }

    string message = find_error_message(json_file, key);
    if (!message.empty()) {
        return message;
    }

    return "null";
}