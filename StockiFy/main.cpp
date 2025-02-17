#include "../include/StockiFy.h"
string program_settings_dir = "Skfy_settings/settings.json";
json settings;

void init_program(){

    try {
        ifstream file(program_settings_dir);
        file >> settings;
        file.close();
    } catch (json::parse_error& e){
        ofstream file;
        file.open(program_settings_dir);
        json settings_obj;
        settings = resettings();
        file << settings;
        file.close();

    }

    ofstream allowed_char;
    allowed_char.open("Skfy_settings/allowed_char.json");
    if (!allowed_char.good()) {
        json allowed_char_obj = re_allowed_char();
        allowed_char << allowed_char_obj;
    }
    allowed_char.close();

    ofstream expected_errors;
    expected_errors.open("Skfy_settings/expected_errors.json");
    if (!expected_errors.good()) {
        json expected_errors_obj = re_expected_errors();
        expected_errors << expected_errors_obj;
    }
    expected_errors.close();


}

int main_menu () {
    
    menu MM_screen;
    MM_screen.set_title("Main Menu");
    MM_screen.set_subtitle("Welcome to StockiFy!");    
    MM_screen.set_body_paragraph("This is a marketplace simulator in which you can sell and buy products. In Order to be able to to sell you will need to check the seller status in Clients settings.");
    MM_screen.set_options_count(5);
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

    init_program();



    main_menu();







    return 0; 
}