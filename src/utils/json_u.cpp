#include <string>
#include <optional>
#include <iostream>
#include <fstream>
#include "../../include/utils/Json_U.h"
#include "../../lib/nlohmann/json.hpp"

using namespace std;


optional<string> read_string_from_json(string file_path, string key) {
    // Read the file
    nlohmann::json json_file;

    try {
        ifstream file(file_path);
        file >> json_file;
        file.close();
    } catch (nlohmann::json::parse_error& e) {;
        return nullopt;
    }

    // Check if the key exists
    if (json_file.find(key) == json_file.end()) {
        return nullopt;
    }

    // Return the value
    return json_file[key];
}

optional<string> read_error_message(string file_path, string error_type, string key){




    return json_file
}

// TODO: Implement the read_error_message function