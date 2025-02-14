#include "../../include/Menu.h"
#include "../../include/Definitions.h"
#include "../../include/Menu_Interactions.h"
#include "../../include/Strings_u.h"
#include "../../include/Terminal_u.h"
#include "../../include/Math_u.h"
#include "../../include/Menu.h"
#include <iostream>
#include <string>
#include <format>
#include <unistd.h>
#include <vector>

using namespace std;


void prtLL(string input, string color, int width, int number_lines){
    if (input != ""){
        cout << color;
        string line = cutLine(input, width - 2);

        for (int i = 0; i < number_lines; i++){            
            cout << cn << '|' << color << line << cn << '|';
        }


        cout << rst;
    }
}

void printL(string input, string color, size_t width){
    if (input != ""){
        cout << color;
        vector<string> lines = adj_to_width(input, width - 2, true, ' ');
        int i = 0;

        do {
            cout << cn << '|' << color << lines[i] << cn << '|' << endl;
            i ++;
        } while (i < static_cast<int>(lines.size()) - 1);

        cout << cn << '|' << color << lines[i] << cn << '|';

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

int initOpt (menu menu) {

    int selected_option = 0;
    char edge = '+';
    string border_color = cn;
    int arrow = 0;


    while (1){
        system("clear");
        int width = getTerminalWidth();         
        string arrow_key = (arrow == 'w')? "up" : "down";
        vector<string> description = adj_to_width(menu.get_option_description(selected_option), width - (width / 3) - 3, true, ' '); 

        cout << rd << edge << border_color << rep_char(width - 2, '=') << rd << edge << endl;

        printC(menu.get_title(), mg, width);
        printC(menu.get_subtitle(), cn, width);
        printL(format(menu.get_body_paragraph()), rst, width);


        cout << endl;
        cout << rd << edge << border_color << rep_char((width / 3), '-') << rd << edge << cn << rep_char((width - (width / 3) - 3), '-') << rd << edge << rst << endl;

        for (int i = 0; i < menu.get_options_count(); i++) {



            if (selected_option != i) {
                prtLL(" + " + menu.get_option(i), rst, (width / 3) + 2, 1); 
            } else {
                prtLL(" > " + menu.get_option(i), gn, (width / 3) + 2, 1);
            }

            if (i < static_cast<int>(description.size())) {
                cout << gn << description[i] << cn << "|" << endl;
            } else {
                cout << rep_char(width - (width / 3) - 3, ' ') << cn << "|" << endl;
            }

        }
        cout << rd << edge << border_color << rep_char(width - 2, '=') << rd << edge << rst << endl;
        cout << endl;
        arrow = getKey();


        if (arrow == 128) {
            selected_option--;
        } else if (static_cast<int>(arrow) == 129) {
            selected_option++;
        } else if (arrow == 10 || arrow == 130 || arrow == 32) {
            break;
        } else {continue;}

        selected_option = (selected_option < 0)? menu.get_options_count() - 1 : selected_option;
        selected_option = (selected_option >= menu.get_options_count())? 0 : selected_option;

    }


    return selected_option;
}

string initInpt () {
    string user_input;


    return user_input;
}



// TODO: Fix: string empty_spaces(width - menu.get_options(i).size() - 10, ' '); << This trow an error when when width is less than line length