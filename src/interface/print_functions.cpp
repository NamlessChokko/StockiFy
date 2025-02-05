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
#include <unistd.h>

using namespace std;


void printL(string input, string color, size_t width){
    if (input != ""){
        cout << color;
        vector<string> text = adj_to_width(input, width - 2, true, ' ');
        string empty_spaces(width - (text[text.size() - 1].size()) - 2, ' ');
        



        for (int i = 0; i < static_cast<int>(text.size()); i++){            
            cout << cn << '|' << color << text[i] << empty_spaces << cn << '|' << endl;
        }
        cout << rst;
    }
};

void printC(string input, string color, size_t width){
    if (input != ""){ 
        int empty_spaces = width - input.length();
        empty_spaces = empty_spaces / 2;
        string left(empty_spaces, ' ');
        string right(width - left.length() - input.length() - 2, ' '); 

        cout << cn << '|';
        cout << color << left << input << right << rst; 
        cout << cn << '|' << rst << endl;
    }
};

void Option_menu(Option_Menu menu, string border_color){
    int width  = getTerminalWidth();
    string strong_line(width - 2, '=');
    string light_line(width - 2, '-');
    char edge = '+';

    system("clear");
    cout << rst;

    cout << rd << edge << border_color << strong_line << rd << edge << rst << endl;

    printC(menu.get_title(), mg, width);
    printC(menu.get_subtitle(), cn, width);
    printL(format(menu.get_body_paragraph()), rst, width);
    cout << rd << edge << border_color << light_line << rd << edge << rst;

    
    cout << "\n";
    string empty_spaces(width - 14, ' ');
    cout << border_color << "|" << mg << "# - "  << "Options:" << empty_spaces << border_color << "|" << rst << endl;
    for (int i = 0; i < menu.get_options_count(); i++){
        string empty_spaces(width - menu.get_options(i).size() - 10, ' ');
        cout << border_color << "|" << cn << "  [" << menu.get_options_keys(i) << "]" << "-> " << gn << menu.get_options(i) << empty_spaces << border_color << "|" << rst << endl;
    }
    cout << rd << edge << border_color << strong_line << rd << edge;
    cout << endl;
    cout << gn << ">>> ";

};

void Input_menu(Input_Menu menu, string border_color){
    int width  = getTerminalWidth();
    string strong_line(width - 2, '=');
    string light_line(width - 2, '-');
    char edge = '+';

    system("clear");
    cout << rst;

    cout << rd << edge << border_color << strong_line << rd << edge << rst << endl;

    printC(menu.get_title(), mg, width);
    printC(menu.get_subtitle(), cn, width);
    printL(format(menu.get_body_paragraph()), rst, width);
    cout << rd << edge << border_color << light_line << rd << edge << rst;


    cout << endl;
    string empty_spaces(width - 19, ' ');
    cout << border_color << "|" << mg << "# - "  << "Requirements:" << empty_spaces << border_color << "|" << rst << endl;
    for (int i = 0; i < menu.get_requirements_count(); i++){
        string empty_spaces(width - menu.get_input_requirement(i).size() - 8, ' ');
        cout << border_color << "|" << cn << "  @" << "-> " << rd << menu.get_input_requirement(i) << empty_spaces << border_color << "|" << rst << endl;
    }
    cout << rd << edge << border_color << strong_line << rd << edge;
    cout << endl;
    cout << gn << menu.get_input_name() << ": " << bk << bg_wt;


};

void Info_menu(Info_Menu menu, string border_color){
    int width  = getTerminalWidth();
    string strong_line(width - 2, '=');
    string light_line(width - 2, '-');
    char edge = '+';

    system("clear");
    cout << rst;

    cout << rd << edge << border_color << strong_line << rd << edge << rst << endl;
    printC(menu.get_title(), mg, width);
    printC(menu.get_subtitle(), cn, width);
    printL(format(menu.get_body_paragraph()), rst, width);
    string _empty_spaces(width - 2, ' ');
    cout << cn << "|" << _empty_spaces << "|";
    string empty_spaces(width - menu.get_information_name().length() - 3, ' ');
    cout << border_color << "|" << mg << menu.get_information_name() << ":" << empty_spaces << border_color << "|";
    printL(menu.get_information(), rst, width);
    cout << rd << edge << border_color << strong_line << rd << edge << rst << endl;
    
    cout << gn << "Press " << "ENTER " << "to continue..." << rst;

};

void Error_screen(int error_code){
    system("clear");
    cout << rst;
    string code = error_handler(error_code);
    int width = getTerminalWidth();
    string strong_line(width - 2, '=');
    string light_line(width - 2, '-');
    char edge = '+';

    error_code = (code == "An unexpected error occurred. Please, check directory json_db/expected_errors.json.") ? 1 : error_code;


    cout << rd << edge << cn << strong_line << rd << edge << endl;
    printC("Error Screen", mg, width);
    printL("An error occurred.", rd, width);
    printL(format("Error code: ["+ to_string(error_code) + "]"), rd, width);
    printL(format(code), rd, width);
    cout << rd << edge << cn << strong_line << rd << edge << endl;
    cout << gn << "Press ENTER to continue...";

};


// TODO: Fix: string empty_spaces(width - menu.get_options(i).size() - 10, ' '); << This trow an error when when width is less than line length