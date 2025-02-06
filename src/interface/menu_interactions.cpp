#include "../../include/Menu_Interactions.h"
#include "../../include/Terminal_u.h"
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
    char scape = getch();
    if (scape != 033){
        return ' ';
    }

    char square = getch();
    if (square != 91){
        return ' ';
    }

    char arrow = getch();
    if (arrow != 'A' && arrow != 'B' && arrow != 'D' && arrow != 'C'){
        return ' ';
    }

    string code = to_string(scape) + square + arrow;

    cout << '\n' << code << endl;

    if (code == "27[A") {
        return 'w';
    } else if (code == "27[B") {
        return 's';
    } else if (code == "27[D") {
        return 'a';
    } else if (code == "27[C") {
        return 'd';
    } else {return ' ';}

    return ' ';
}



