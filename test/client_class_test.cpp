#include "../include/StockiFy.h"
#include <string.h>
#include <iostream>
#include <unistd.h>

using namespace std;



void setting_new_value (Client client1){
    string new_name = "";
    string new_description = "";
    bool new_seller_status = true;
    char c = ' ';

    cout << "\n" << endl;
    cout << "Enter new client name, description and seller status: " << endl;
    cout << "Name: ";
    getline(cin, new_name);
    cout << "Description: ";
    getline(cin, new_description);
    cout << "Seller status(1 for True): ";
    c = std::cin.get();

    new_seller_status = (c == '1')? true : false;

    // Client info is changed 
    cout << "\n\n" << "Setting client info: " << endl;

    cout << "New Client name: " << new_name << endl;
    if (!client1.set_client_name(new_name)){
        cout << "Error: Invalid name" << endl;
    } else {
        cout << "Client name set successfully" << endl;
    }

    cout << "New Client description: " << new_description << endl;
    if (!client1.set_client_description(new_description)){
        cout << "Error: Invalid description" << endl;
    } else {
        cout << "Client description set successfully" << endl;
    }

    cout << "Is Client is seller: " << new_seller_status << endl;
    if (!client1.set_seller_in(new_seller_status)){
        cout << "Error: Invalid seller status" << endl;
    } else {
        cout << "Client seller status set successfully" << endl;
    }

    cout << "\n\n" << "New client info: " << endl;
    cout << "Client name: " << client1.get_client_name() << endl;
    cout << "Client description: " << client1.get_client_description() << endl;
    cout << "Client seller status: " << client1.is_client_seller() << endl;


}

int main (){

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        std::cout << "Current working directory: " << cwd << std::endl;
    }


    Client client1("John Doe", false); // Create a client object with name John Doe and seller status false
    client1.print_client_info(); // Print the client info

    cout << "Press ENTER to continue..." << endl;
    std::cin.ignore();

    while (true){
        setting_new_value(client1); 
        

        cout << "Press ENTER to continue..." << endl;
        std::cin.ignore();
    }


    system("clear");
    return 0;
}

