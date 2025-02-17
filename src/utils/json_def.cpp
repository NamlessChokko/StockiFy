#include "../../include/Json_def.h"

json re_allowed_char (){
    return json::parse(R"(
    {
        "default_allowed_char" : "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_",
        
        "client_name" : "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ",
        "client_description" : "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_!@.#$%^&*() ",
        "client_email" : "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_@.",

        "item_name" : "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ",
        "item_description" : "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_!@.#$%^&*() "
        
    }
    )");
}

json re_expected_errors (){
    return json::parse(R"(
    {
        "database_crud" : {
            "101" : "Database connection failed"
        },

        "run_time" : {
            "201" : "Error in running the code"
        },

        "menu_input" : {
            "302" : "Invalid input. Please try again.",
            "303" : "Inexistent option selected. Pleas try again ",
            "304" : "There was an error during the validation of the input. Please check directory: 'Skfy_settings/allowed_char.json' and the program documentation.",
            "305" : "Invalid input: You entered an invalid character. Please try again.",
            "306" : "Invalid input: The input can no end with an empty space. Please try again.",
            "307" : "Invalid input: The input can no start with an empty space. Please try again.",
            "308" : "Invalid input: The input can have not empty spaces. Please try again.",
            "309" : "Invalid input: The input is too short. Please try again.",
            "310" : "Invalid input: The input exceeds the character limit. Please try again."

        },

        "Interaction_permissions" : {
            "401" : "Client does not have permission",
            "402" : "Current client does not have permission to change seller status." 
        },

        "validating_data" : {
            "501" : "Invalid data."
        },

        "file_handling" : {
            "601" : "Error in reading the file."
        },

        "client_input" : {
            "701" : "Invalid input for client name, please enter a valid name.",
            "702" : "Invalid input for client description, please enter a valid description"
        }

    }
    )");
}

json resettings (){
    return json::parse(R"(
    {
        "settings" : {
            "directory" : "Skfy_settings",
            "allowed_char_file" : "allowed_char.json",
            "expected_errors_file" : "expected_errors.json"
        }
    }
    )");
}