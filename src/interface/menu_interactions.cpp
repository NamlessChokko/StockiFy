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

char getKey() {
    char first = '\0';
    char second = '\0';
    char third = '\0';

    first = getch();
    if (first != 27) { // Si no es la tecla ESC (27), se devuelve directamente
        return first;
    }

    // Si la primera tecla es ESC (posible tecla especial)
    second = getch();

    if (second == '[') { 
        third = getch();

        switch (third) {
            case 'A': return 128; // Flecha arriba
            case 'B': return 129; // Flecha abajo
            case 'C': return 130; // Flecha derecha
            case 'D': return 131; // Flecha izquierda

            case '5': 
                if (getch() == '~') return 136; // Page Up
                break;
            case '6': 
                if (getch() == '~') return 137; // Page Down
                break;

            case 'H': return 140; // Home
            case 'F': return 141; // End
            case '2': 
                if (getch() == '~') return 142; // Insert
                break;
            case '3': 
                if (getch() == '~') return 143; // Delete
                break;

            case '1': 
                if (getch() == ';' && getch() == '5') { 
                    char ctrlArrow = getch();
                    switch (ctrlArrow) {
                        case 'A': return 132; // Ctrl + Arriba
                        case 'B': return 133; // Ctrl + Abajo
                        case 'C': return 134; // Ctrl + Derecha
                        case 'D': return 135; // Ctrl + Izquierda
                    }
                }
                break;
        }
    } else if (second == 'O') { 
        third = getch();
        switch (third) {
            case 'P': return 144; // F1
            case 'Q': return 145; // F2
            case 'R': return 146; // F3
            case 'S': return 147; // F4
        }
    }

    return -1; // Retorno en caso de que no se detecte ninguna tecla válida
}

