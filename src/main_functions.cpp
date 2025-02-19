#include "../include/Main_Functions.h"

void init_program(){
    string settings_path = "Skfy_settings/settings.json";
    string allowed_char_path = "Skfy_settings/allowed_char.json";
    string expected_errors_path = "Skfy_settings/expected_errors.json";

    cout << yl << "Reading execution essential files..." << endl;   

    cout << cn << "Reding Settings file..." << endl;
    fstream settings(settings_path);
    if (!settings) {
        cout << rd << "Settings file not found." << endl;
        cout << cn << "Creating new settings files..." << endl;
        makeFile_s("settings.json", "Skfy_settings");
        enter_obj(settings_path, "settings");
    }
    settings.close();
    cout << gn << "Settings file setted correctly." << endl; 

    cout << cn << "Reading allowed char file..." << endl;
    fstream allowed_char(allowed_char_path); 
    if (!allowed_char) {
        cout << rd << "Allowed char file not found." << endl;
        cout << cn << "Creating new allowed char file..." << endl;  
        makeFile_s("allowed_char.json", "Skfy_settings");
        enter_obj(allowed_char_path, "allowed_char");
        cout << gn << "Files created correctly." << endl;
    } else {
        if ( !compare_file(allowed_char_path, json_objs("allowed_char"))) {
            cout << rd << "Allowed char file was modified." << endl;
            cout << cn << "Fixing allowed char..." << endl;
            enter_obj(allowed_char_path, "allowed_char");
            cout << gn << "Allowed char file fixed correctly." << endl;
        }
    }
    cout << gn << "Allowed char file setted correctly." << endl;


    cout << cn << "Reading expected errors file..." << endl;
    fstream expected_errors(expected_errors_path); 
    if (!expected_errors) {
        cout << rd << "Expected errors file not found." << endl;
        cout << cn << "Creating expected errors file..." << endl;
        makeFile_s("expected_errors.json", "Skfy_settings");
        enter_obj(expected_errors_path, "expected_errors");
        cout << gn << "Files created correctly." << endl;
    } else {
        if (!compare_file(expected_errors_path, json_objs("expected_errors"))) {
            cout << rd << "Expected errors file was modified." << endl;
            cout << cn << "Fixing Expected errors..." << endl;
            enter_obj(expected_errors_path, "expected_errors");
            cout << gn << "Expected errors file fixed correctly." << endl;
        }
    }
    cout << gn << "Expected errors file setted correctly." << endl;
}

void connect_to_database () {
    system("clear");
    cout << rst; 

    printL("We need the login information to connect with the database. This information is not stored and will be reset when you leave the program", cn, getTerminalWidth(), false);
    cout << "Press ENTER to continue...";
    getch();

    string name = input("Enter your database user name.", "Name", "user", 4, 50, false, false);
    string password = input("Enter your password.", "Password",  "password", 8, 50, true, true);
    



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

    return initOpt(MM_screen);
}
