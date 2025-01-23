#include <string>
#include <optional>
#include <iostream>
#include <fstream>
#include "../../include/utils/Json_U.h"
#include "../../lib/nlohmann/json.hpp"

using namespace std;
using namespace nlohmann;


optional<string> get_string(string file_path, string key) {
    json json_file;

    try {
        ifstream file(file_path);
        file >> json_file;
        file.close();
    } catch (json::parse_error& e) {;
        return nullopt;
    }

    if (json_file.find(key) == json_file.end()) {
        return nullopt;
    }

    return json_file[key];
}

optional<string> read_error_message(string file_path, string error_type, string key){

    json json_file;

    try {
        ifstream file(file_path);
        file >> json_file;
        file.close();
    } catch (json::parse_error& e) {;
        return nullopt;
    }


    return json_file[error_type][key];
}
