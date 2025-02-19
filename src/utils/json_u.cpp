#include "../../include/Json_u.h"

string get_value(string key, string file_path) {
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

string makeFile_s (string name, string file_dir) {
    fs::path directory(file_dir);
    if (!fs::exists(directory)) {
        fs::create_directories(directory);
    }
    fs::path file_path = directory / name;
    std::ofstream file(file_path);
    if (!file.is_open()) {
        return ""; 
    }

    return file_path;
}

int enter_obj (string file_path, string obj){
    ofstream file(file_path);

    if (!file.is_open()) {
        return 1;
    }

    try {
        json object = json_objs(obj);
        file << object.dump(4);
    } catch (json::parse_error& e){
        cerr << rd << "Error: \n" << e.what() << rst << endl;
        exit(1);
    }

    return 0;
}

bool compare_file (string _file, json expected){
    ifstream file(_file);

    if (!file) {
        return false;
    }

    try {
        json object;
        file >> object; 
        if (object != expected) {
            return false;
        }
    } catch (json::parse_error& e) {
        return false; 
    }

    return true;
};
