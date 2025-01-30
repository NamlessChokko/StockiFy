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

    Input_Menu menu;
    
    // Configurar el menú con datos de prueba
    menu.set_title("Name");
    menu.set_subtitle("Name test menu");
    menu.set_body_paragraph(format("We need your ^cnname*rs to identify you"));
    menu.set_input_name("Name");
    
    // Establecer requisitos
    menu.set_requirements_count(3);
    menu.set_input_requirements(format("Must be a ^gnvalid name*rs."), 0);
    menu.set_input_requirements(format("No ^rdspecial char*rs allowed"), 1);
    menu.set_input_requirements(format("No ^rdnumbers*rs allowed"), 2);
    
    // Llamar a la función para mostrar el menú
    Input_menu(menu);
    std::cin.ignore();




    cout << "Press " << bl <<"ENTER " << rst << "to continue..." << endl;
    //std::cin.ignore();
    system("clear");
    return 0;
}

