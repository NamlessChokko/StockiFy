#include "../include/StockiFy.h"

void init_program(){
    string settings_path = "Skfy_settings/settings.json";
    string allowed_char_path = "Skfy_settings/allowed_char.json";
    string expected_errors_path = "Skfy_settings/expected_errors.json";

    fstream settings(settings_path);
    if (!settings) {
        makeFile_s("settings.json", "Skfy_settings");
        enter_obj(settings_path, "settings");
    }
    settings.close();

    fstream allowed_char(allowed_char_path); 
    if (!allowed_char) {
        makeFile_s("allowed_char.json", "Skfy_settings");
        enter_obj(allowed_char_path, "allowed_char");
    } else {
        json curr_obj;
        allowed_char >> curr_obj;
        allowed_char.close();

        if (curr_obj != json_objs("allowed_char")) {
            enter_obj(allowed_char_path, "allowed_char");
            curr_obj.clear();
        }
    }

    fstream expected_errors(expected_errors_path); 
    if (!expected_errors) {
        makeFile_s("expected_errors.json", "Skfy_settings");
        enter_obj(expected_errors_path, "expected_errors");
    } else {
        json curr_obj;
        expected_errors >> curr_obj;
        expected_errors.close();

        if (curr_obj != json_objs("expected_errors")) {
            enter_obj(expected_errors_path, "expected_errors");
            curr_obj.clear();
        }
    }

}

int main_menu () {
    
    menu MM_screen;
    MM_screen.set_title("Main Menu");
    MM_screen.set_subtitle("Welcome to StockiFy!");    
    MM_screen.set_body_paragraph("This is a marketplace simulator in which you can sell and buy products. In Order to be able to to sell you will need to check the seller status in Clients settings.");
    MM_screen.set_options_count(6);
    MM_screen.set_options("Search products", 0);
    MM_screen.set_option_description("Search for products on sale so you can add them to your cart and then proceed to pay.", 0);
    MM_screen.set_options("Sell Products", 1);
    MM_screen.set_option_description("If you have enable the seller status, you can place a sell order.", 1);
    MM_screen.set_options("Client Settings", 2);
    MM_screen.set_option_description("Adjust your Client information: name, description, email etc. You can set your seller status as well.", 2);
    MM_screen.set_options("Interface Settings", 3);
    MM_screen.set_option_description("Modify the terminal interface appearance, file directions, and some functionalities.", 3);
    MM_screen.set_options("Program Information", 4);
    MM_screen.set_option_description("Shows some essential information about how the program works, errors that can ocurs and how to fix it, and developer data.", 4); 
    MM_screen.set_options("Exit the Program", 5);
    MM_screen.set_option_description("Close the program and disconnect the SQL server.", 5);

    initOpt(MM_screen);

}


int main(int argc, char *argv[]) {
    system("clear");
    cout << rst;
    init_program();
    // main_menu();

    return 0; 
}