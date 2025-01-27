#include <string>
#include <optional>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "../include/Json_U.h"
#include "../lib/nlohmann/json.hpp"

using namespace std;
using namespace nlohmann;


optional<string> get_string(string file_path, string key) {
    json json_file;

    try {
        ifstream file(file_path);
        file >> json_file;
        file.close();
    } catch (json::parse_error& e) {
        cout << "Error: " << e.what() << endl;
        cout << "Could not open file: " << file_path << endl;
        cout << "This is a unexpected error, please check documentation for more information" << endl;
        cout << "Exiting..." << endl;
        exit(1);
    }

    if (json_file.find(key) == json_file.end()) {
        return nullopt;
    }

    return json_file[key];
}

optional<string> read_error_message(string file_path, string error_type, int error_number){

    json json_file;
    string key = to_string(error_number); 

    try {
        ifstream file(file_path);
        file >> json_file;
        file.close();
    } catch (json::parse_error& e) {;
        cout << "Error: " << e.what() << endl;
        cout << "Could not open file: " << file_path << endl;
        cout << "This is a unexpected error, please check documentation for more information" << endl;
        cout << "Exiting..." << endl;
        exit(1);
    }


    return json_file[error_type][key];
}
