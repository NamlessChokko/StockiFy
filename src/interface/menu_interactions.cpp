#include "../../include/Menu_Interactions.h"
#include "../../include/Terminal_u.h"
#include "../../include/Json_u.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
const int ESC = 033;
const int SQR_BRCKT = 91;

string error_handler (
    int error_number
){
    return  read_error_message(error_number, "json_db/expected_errors.json");
}

int validate_option (
    char input,
    int number_of_options = 3,
    vector<char> options = {'1', '2', '3'}
){
    char option;
    try{
        option = input;
    }
    catch (exception& e){   
        return 301;
    }

    for (int i = 0; i < number_of_options; i++){
        if (option == options[i]){
            return 302;
        }
    }

    return 0;
}


char get_arrow(){
    if (getch() != ESC){ // If it is not the scape character, then return a empty value
        return ' ';
    }

    if (getch() != SQR_BRCKT){
        return ' ';
    }

    char arrow = getch(); // Get tha actual arrow value represented in letters (A = up, B = down, C = right, D = left) 
    
    if (arrow == 'A'){
        return 'w';
    } else if (arrow == 'B'){
        return 's';
    } else if (arrow == 'C'){
        return 'd';
    } else if (arrow == 'D'){
        return 'a';
    } else {
        cin.ignore(); // Three ignores in case the user holds ctrl keys 
        cin.ignore();
        cin.ignore();
        return ' '; // Return a empty value if the arrow is not recognized
    }

}



