#include "../../include/Option_Menu_c.h"
#include "../../include/Input_Menu_c.h"
#include "../../include/Info_Menu_c.h"
#include "../../include/Definitions.h"
#include "../../include/Menu_Interactions.h"
#include "../../include/Strings_u.h"
#include "../../include/Getch.h"
#include <iostream>
#include <string>
#include <format>

using namespace std;


void Option_menu(Option_Menu menu){
    system("clear");
    cout << rst;
    
    if (menu.get_title() != ""){
        cout << mg << menu.get_title() << rst << endl;  
    }

    if (menu.get_subtitle() != ""){
        cout << cn << menu.get_subtitle() << rst << endl;   
    }

    if (menu.get_body_paragraph() != ""){
        cout << menu.get_body_paragraph() << endl;
    }

    cout << endl;
    cout << cn << "Options:" << rst << endl;
    for (int i = 0; i < menu.get_options_count(); i++){
        cout << gn << "[" << i+1 << "]" << "-> " << rst  << menu.get_options(i) << rst << endl;
    }
    cout << gn << ">>> ";

};

void Input_menu(Input_Menu menu){
    system("clear");
    cout << rst;

    if (menu.get_title() != ""){
        cout << mg << menu.get_title() << rst << endl;  
    }

    if (menu.get_subtitle() != ""){
        cout << cn << menu.get_subtitle() << rst << endl;   
    }

    if (menu.get_body_paragraph() != ""){
        cout << menu.get_body_paragraph() << endl;
    }
    
    cout << endl;
    cout << cn << "Requirements: " << rst << endl;
    for (int i = 0; i < menu.get_requirements_count(); i++){
        cout << rd << "@" << "-> " << rst  << menu.get_input_requirement(i) << rst << endl;
    }
    cout << gn << menu.get_input_name() << ": " << bk << bg_wt;


};

void Info_menu(Info_Menu menu){
    system("clear");
    cout << rst;

    if (menu.get_title() != ""){
        cout << mg << menu.get_title() << rst << endl;  
    }

    if (menu.get_subtitle() != ""){
        cout << cn << menu.get_subtitle() << rst << endl;   
    }

    if (menu.get_body_paragraph() != ""){
        cout << menu.get_body_paragraph() << endl;
    }

    cout << endl;
    cout << rst << menu.get_information_name() << ": ";
    cout << cn << menu.get_information() << rst << endl;
    cout << gn << "Press " << "ENTER " << "to continue..." << rst;

};

void Error_screen(int error_code){
    system("clear");
    string code = error_handler(error_code);

    error_code = (code == "An unexpected error occurred. Please, check directory json_db/expected_errors.json.") ? 1 : error_code;

    cout << mg << "An error occurred." << rst << endl;
    cout << cn << "Error code: " << rd << "["<< error_code << "]" << rst << endl;
    cout << rst << format(code) << endl;
    cout << gn << "Press " << "ENTER " << "to continue..." << rst;
    getch();
    system("clear");
};

