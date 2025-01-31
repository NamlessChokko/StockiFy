#include "../../include/Menu_Interactions.h"
#include "../../include/getch.h"
#include "../../include/Json_u.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;


string error_handler (
    int error_number
){
    return  read_error_message(error_number, "json_db/expected_errors.json");
}

int validate_option (
    int number_of_options = 3,
    vector<char> options = {'1', '2', '3'}
){
    char option;
    try{
        getch() >> option;
    }
    catch (exception& e){   
        return 1;
    }

    for (int i = 0; i < number_of_options; i++){
        if (option == options[i]){
            return 2;
        }
    }

    return 0;
}



