#include "../include/StockiFy.h"
#include <string.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main (){
    system("clear");
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    cout << bl << "Current working dir: " << rst << cwd << endl;

    Info_Menu menu;
    
    // Configurar el menú con datos de prueba
    menu.set_title("Main Menu");
    menu.set_subtitle("Valance Information");
    menu.set_body_paragraph("This is your valance information.");
    menu.set_information_name("Your current valance is");
    menu.set_information("1000");
    
    // Llamar a la función para mostrar el menú
    Info_menu(menu);


    cout << rst;
    getch();

    Error_screen(1023);


    system("clear");
    return 0;
}

