#include "../../include/Option_Menu_c.h"
#include "../../include/Print_Functions.h"
#include "../../include/Definitions.h"
#include "../../include/Strings_u.h"
#include <iostream>
#include <string>
#include <format>

using namespace std;


void print_Option_menu(Option_Menu menu){
    system("clear");
    cout << rst;
    cout << mg << menu.get_menu_title() << rst << endl;  
    cout << cn << menu.get_menu_subtitle() << rst << endl;   
    cout <<  menu.get_menu_body_paragraph() << endl;
    cout << "\n";
    cout << cn << "Options:" << rst << endl;

    for (int i = 0; i < menu.get_options_count(); i++){
        cout << gn << "[" << i+1 << "]" << "-> " << rst  << menu.get_options(i) << rst << endl;
    }
    cout << gn << ">>> ";

};
