#include "../include/StockiFy.h"
#include "../include/getch.h"
#include <string.h>
#include <iostream>
#include <unistd.h>

using namespace std;

void changing_and_showing
(
    Client client,
    string new_name, 
    string new_description,
    bool new_seller_status
){

    cout << "Changing values..." << endl;

    if (!client.set_client_name(new_name)){
        cout << "invalid name" << endl;
    }else {cout << "valid name" << endl;}

    if (!client.set_client_description(new_description)){
        cout << "invalid description" << endl;
    }else {cout << "valid description" << endl;}

    client.set_seller_in(new_seller_status);
    cout << "\n";

    cout << "================================================" << endl;
    cout << "New Client name: " << gn << client.get_client_name() << rst << endl;
    cout << "New Client description: " << gn << client.get_client_description() << rst << endl;
    cout << "Is Client seller? -> " << gn << client.is_client_seller() << rst << endl;
    cout << "\n";

}

void cleaning_data(Client client){
    cout << "Cleaning client data..." << endl;
    client.clean_client_info();
    client.print_client_info();
    cout << "\n";

}

int main (){
    system("clear");
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    cout << "Current working dir: " << cwd << endl;


    char c = 'a';


    Option_Menu menu;
    menu.set_menu_name("Menu Class Test");
    menu.set_menu_title("Menu Class Test Title");
    menu.set_menu_subtitle("Menu Class Test Subtitle");
    menu.set_menu_body_paragraph("This test will show the functionality of the Menu class: body paragraph");
    menu.set_options_count(4);
    menu.set_options("Open menu again", 0);
    menu.set_options("Option 2", 1);
    menu.set_options("Option 3", 2);
    menu.set_options("Exit", 3);

    print_Option_menu(menu);
    cout << rst;
    c = getch();
    system("clear");

    switch (c) {
        case '1':
            print_Option_menu(menu);
            getch();
            break;
        case '2':
            cout << "Option 2 selected" << endl;
            break;
        case '3':
            cout << "Exit selected" << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
    }




    cout << "Press ENTER to continue..." << c << endl;
    std::cin.ignore();
    system("clear");
    return 0;
}

