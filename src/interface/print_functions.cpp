#include "../../include/Option_Menu_c.h"
#include "../../include/Input_Menu_c.h"
#include "../../include/Info_Menu_c.h"
#include "../../include/Definitions.h"
#include "../../include/Menu_Interactions.h"
#include "../../include/Strings_u.h"
#include "../../include/Terminal_u.h"
#include <iostream>
#include <string>
#include <format>

using namespace std;


void printL(string input, string color, int width){
    if (input != ""){
        cout << color;
        vector<string> text = adj_to_width(input, width - 2);
        string empty_spaces(width - 2 - (text[text.size() - 1].size()), ' ');
        for (int i = 0; i < static_cast<int>(text.size()); i++){
            
            if (i == static_cast<int>(text.size()) - 1){
                cout << '|' << text[i] << empty_spaces <<  '|' << endl;
                break;
            }


            cout << '|' << text[i] << '|' << endl;
        }
        cout << rst;
    }

};

void printC(string input, string color, int width){
    int empty_spaces = width - input.length();
    empty_spaces = empty_spaces / 2;

    cout << '|';
    for (int i = 0; i < empty_spaces - 1; i++){
        cout << " ";
    }

    cout << color << input << rst; 

    for (int i = 0; i < empty_spaces - 1; i++){
        cout << " ";
    }
    cout << '|' << endl;
};

void Option_menu(Option_Menu menu){
    system("clear");
    cout << rst;
    int width  = getTerminalWidth();
    
    cout << "+";
    for (int i = 0; i < width - 2; i++){
        cout << "-";
    }
    cout << "+" << endl;

    printC(menu.get_title(), mg, width);
    printC(menu.get_subtitle(), cn, width);
    printL(format(menu.get_body_paragraph()), rst, width);

    cout << endl;
    cout << cn << "Options:" << rst << endl;
    for (int i = 0; i < menu.get_options_count(); i++){
        cout << gn << "[" << menu.get_options_keys(i) << "]" << "-> " << rst  << menu.get_options(i) << rst << endl;
    }
    cout << gn << ">>> ";

};

void Input_menu(Input_Menu menu){
    system("clear");
    cout << rst;
    int width  = getTerminalWidth();
    
    printC(menu.get_title(), mg, width);
    printC(menu.get_subtitle(), cn, width);
    printL(format(menu.get_body_paragraph()), rst, width);

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
    int width  = getTerminalWidth();
    
    printC(menu.get_title(), mg, width);
    printC(menu.get_subtitle(), cn, width);
    printL(format(menu.get_body_paragraph()), rst, width);

    cout << endl;
    cout << rst << menu.get_information_name() << ": ";
    cout << cn << menu.get_information() << rst << endl;
    cout << gn << "Press " << "ENTER " << "to continue..." << rst;

};

void Error_screen(int error_code){
    system("clear");
    string code = error_handler(error_code);
    int width = getTerminalWidth();

    error_code = (code == "An unexpected error occurred. Please, check directory json_db/expected_errors.json.") ? 1 : error_code;

    cout << mg << "An error occurred." << rst << endl;
    cout << cn << "Error code: " << rd << "["<< error_code << "]" << rst << endl;
    printL(format(code), rst, width);
    cout << gn << "Press " << "ENTER " << "to continue..." << rst;
    getch();
    system("clear");
};

