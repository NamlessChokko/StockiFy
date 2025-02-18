#include "../../include/Print_Functions.h"


void prtLL(string input, string color, int width, int number_lines, bool has_border){
    if (input != ""){
        cout << color;
        string border = (has_border)? "|" : "";
        string line = cutLine(input, width - 2 * (border.length()));

        for (int i = 0; i < number_lines; i++){            
            cout << cn << border << color << line << cn << border;
        }


        cout << rst;
    }
}

void printL(string input, string color, size_t width, bool has_border){
    if (input != ""){
        cout << color;
        string border = (has_border)? "|" : ""; 
        vector<string> lines = adj_to_width(input, width - 2 * (border.length()), true, ' ');
        int i = 0;
        if (lines.size() > 1){
            do {
                cout << cn << border << color << lines[i] << cn << border << endl;
                i ++;
            } while (i < static_cast<int>(lines.size()) - 1);
        }

        cout << cn << border << color << lines[i] << cn << border;
        cout << rst;
    }
};

void printC(string input, string color, size_t width, bool has_border){
    if (input != ""){ 
        int empty_spaces = width - input.length();
        empty_spaces = empty_spaces / 2;
        string border = (has_border)? "|" : "";
        string left(empty_spaces, ' ');
        string right(width - left.length() - input.length() - 2 * (border.length()), ' '); 

        cout << cn << border;
        cout << color << left << input << right << rst; 
        cout << cn << border << rst << endl;
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
        vector<string> description = adj_to_width(menu.get_option_description(selected_option), width - (width / 3) - 3, true, ' '); 

        cout << rd << edge << border_color << rep_char(width - 2, '=') << rd << edge << endl;

        printC(menu.get_title(), mg, width, true);
        printC(menu.get_subtitle(), cn, width, true);
        printL(format(menu.get_body_paragraph()), rst, width, true);


        cout << endl;
        cout << rd << edge << border_color << rep_char((width / 3), '-') << rd << edge << cn << rep_char((width - (width / 3) - 3), '-') << rd << edge << rst << endl;

        for (int i = 0; i < menu.get_options_count(); i++) {



            if (selected_option != i) {
                prtLL(" + " + menu.get_option(i), rst, (width / 3) + 2, 1, true); 
            } else {
                prtLL(" > " + menu.get_option(i), gn, (width / 3) + 2, 1, true);
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

string input (
    string _prompt, 
    string input_name,
    string key,
    int minimum_length,
    int maximum_length,
    bool start_space,
    bool end_space
) {

    while (1) {
        system("clear");
        cout << rst;
        int width = getTerminalWidth();
        vector<string> prompt = adj_to_width(_prompt, width, true, ' ');

        for (int i = 0; i < static_cast<int>(prompt.size()); i++){
            cout << cn << prompt[i] << endl;
        }
        cout << gn << input_name << ": " << gn;
        string input;
        getline(cin, input, '\n');
        cout << rst;

        int error_code = is_valid_string(input, key, minimum_length, maximum_length, start_space, end_space);


        if (!error_code) {
            return input;
        } else {
            string error = read_error_message(error_code, "Skfy_settings/expected_errors.json");

            cout << rd << "Error: " << error_code << endl;
            printL(error, rd, width, false);
            cout << gn << "Press ENTER to continue..." << rst;
            getch();
            continue;
        }

    }


}