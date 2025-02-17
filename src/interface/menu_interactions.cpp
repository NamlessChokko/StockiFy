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
    return  read_error_message(error_number, "Skfy_settings/expected_errors.json");
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

// Mapa de teclas especiales a valores ASCII personalizados
int getKey() {
    char code[5] = {'\0'};

    code[1] = getch();
    if (code[1] != 27) { // Si no es ESC, devuelve la tecla directamente
        return code[1];
    }

    // Si la primera tecla es ESC, es una tecla especial
    code[2] = getch();

    if (code[2] == '[') {
        code[3] = getch();

        switch (code[3]) {
            case 'A': return 128; // Flecha arriba
            case 'B': return 129; // Flecha abajo
            case 'C': return 130; // Flecha derecha
            case 'D': return 131; // Flecha izquierda

            case 'H': return 140; // Home
            case 'F': return 141; // End

            case '2':
                code[4] = getch();
                if (code[4] == '~') return 142; // Insert
                break;

            case '3':
                code[4] = getch();
                if (code[4] == '~') return 143; // Delete
                break;

            case '5':
                code[4] = getch();
                if (code[4] == '~') return 136; // Page Up
                break;

            case '6':
                code[4] = getch();
                if (code[4] == '~') return 137; // Page Down
                break;

            case '1': // Posibles combinaciones Ctrl + Flechas o Ctrl + Home/End
                code[4] = getch();
                if (code[4] == ';') {
                    char modifier = getch(); // Verificamos el modificador
                    if (modifier == '5') { // Ctrl está presionado
                        char ctrlKey = getch();
                        switch (ctrlKey) {
                            case 'A': return 132; // Ctrl + Arriba
                            case 'B': return 133; // Ctrl + Abajo
                            case 'C': return 134; // Ctrl + Derecha
                            case 'D': return 135; // Ctrl + Izquierda
                            case 'H': return 138; // Ctrl + Home
                            case 'F': return 139; // Ctrl + End
                        }
                    } else if (modifier == '2'){
                        char shftKey = getch();
                        switch (shftKey) {
                            case 'A': return 156; // Shift + Arriba
                            case 'B': return 157; // Shift + Abajo
                            case 'C': return 158; // Shift + Derecha
                            case 'D': return 159; // Shift + Izquierda
                            case 'H': return 160; // Shift + Home
                            case 'F': return 161; // Shift + End
                        }
                    }
                }
                break;
        }
    } else if (code[2] == 'O') { 
        code[3] = getch();
        switch (code[3]) {
            case 'P': return 144; // F1
            case 'Q': return 145; // F2
            case 'R': return 146; // F3
            case 'S': return 147; // F4
            default:
                if (code[3] >= 't' && code[3] <= 'v') {
                    return 148 + (code[3] - 't'); // F5-F7
                } else if (code[3] >= 'w' && code[3] <= 'y') {
                    return 151 + (code[3] - 'w'); // F8-F10
                }
                break;
        }
    } else if (code[2] == '1') { // Para F11 y F12
        code[3] = getch();
        if (code[3] == '1') {
            code[4] = getch();
            if (code[4] == '~') return 154; // F11
        } else if (code[3] == '2') {
            code[4] = getch();
            if (code[4] == '~') return 155; // F12
        }
    }

    return -1; // No se detectó ninguna tecla especial válida
}



