#include "../../include/Option_Menu_c.h"
#include "../../include/Input_Menu_c.h"
#include "../../include/Definitions.h"
#include <iostream>
#include <string>
#include <format>

using namespace std;


void Option_menu(Option_Menu menu){
    system("clear");
    cout << rst;
    cout << mg << menu.get_title() << rst << endl;  
    cout << cn << menu.get_subtitle() << rst << endl;   
    cout <<  menu.get_body_paragraph() << endl;
    cout << "\n";
    cout << cn << "Options:" << rst << endl;

    for (int i = 0; i < menu.get_options_count(); i++){
        cout << gn << "[" << i+1 << "]" << "-> " << rst  << menu.get_options(i) << rst << endl;
    }
    cout << gn << ">>> ";

};

void Input_menu(Input_Menu menu){
    system("clear");
    cout << rst;
    cout << mg << menu.get_title() << rst << endl;  
    cout << cn << menu.get_subtitle() << rst << endl;   
    cout <<  menu.get_body_paragraph() << endl;
    cout << cn << "Requirements: " << rst << endl;

    for (int i = 0; i < menu.get_requirements_count(); i++){
        cout << rd << "[" << i+1 << "]" << "-> " << rst  << menu.get_input_requirement(i) << rst << endl;
    }
    cout << gn << menu.get_input_name() << ": " << bk << bg_wt;


};


// Fix methods names 