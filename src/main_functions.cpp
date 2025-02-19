#include "../include/Main_Functions.h"

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

void init_program(){
    string settings_path = "Skfy_settings/settings.json";
    string allowed_char_path = "Skfy_settings/allowed_char.json";
    string expected_errors_path = "Skfy_settings/expected_errors.json";

    cout << yl << "Reading execution essential files..." << endl;   

    cout << cn << "Reding Settings file..." << endl;
    fstream settings(settings_path);
    if (!settings) {
        cout << rd << "Settings file not found." << endl;
        cout << cn << "Creating new settings files..." << endl;
        makeFile_s("settings.json", "Skfy_settings");
        enter_obj(settings_path, "settings");
    }
    settings.close();
    cout << gn << "Settings file setted correctly." << endl; 

    cout << cn << "Reading allowed char file..." << endl;
    fstream allowed_char(allowed_char_path); 
    if (!allowed_char) {
        cout << rd << "Allowed char file not found." << endl;
        cout << cn << "Creating new allowed char file..." << endl;  
        makeFile_s("allowed_char.json", "Skfy_settings");
        enter_obj(allowed_char_path, "allowed_char");
        cout << gn << "Files created correctly." << endl;
    } else {
        if ( !compare_file(allowed_char_path, json_objs("allowed_char"))) {
            cout << rd << "Allowed char file was modified." << endl;
            cout << cn << "Fixing allowed char..." << endl;
            enter_obj(allowed_char_path, "allowed_char");
            cout << gn << "Allowed char file fixed correctly." << endl;
        }
    }
    cout << gn << "Allowed char file setted correctly." << endl;


    cout << cn << "Reading expected errors file..." << endl;
    fstream expected_errors(expected_errors_path); 
    if (!expected_errors) {
        cout << rd << "Expected errors file not found." << endl;
        cout << cn << "Creating expected errors file..." << endl;
        makeFile_s("expected_errors.json", "Skfy_settings");
        enter_obj(expected_errors_path, "expected_errors");
        cout << gn << "Files created correctly." << endl;
    } else {
        if (!compare_file(expected_errors_path, json_objs("expected_errors"))) {
            cout << rd << "Expected errors file was modified." << endl;
            cout << cn << "Fixing Expected errors..." << endl;
            enter_obj(expected_errors_path, "expected_errors");
            cout << gn << "Expected errors file fixed correctly." << endl;
        }
    }
    cout << gn << "Expected errors file setted correctly." << endl;
}

