#include "../include/StockiFy.h"
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
    cout << "New Client name: " << client.get_client_name() << endl;
    cout << "New Client description: " << client.get_client_description() << endl;
    cout << "Is Client seller? -> " << client.is_client_seller() << endl;
    cout << "\n";

}

void cleaning_data(Client client){
    cout << "Cleaning client data..." << endl;
    client.clean_client_info();
    client.print_client_info();
    cout << "\n";

}

int main (){
    Client new_client ("new name", 0);
    string name = "";
    string description = "";
    int seller = 0;

    while (1){
        cout << "Enter new name: "; 
        getline(cin, name);
        cout << "Enter new description: ";
        getline(cin, description);
        cout << "Enter new seller status: ";
        std::cin >> seller; 
        cout << "\n";

        changing_and_showing(new_client, name, description, seller);
        cleaning_data(new_client);

        cout << "Press ENTER to continue, \"q\" for quit..." << endl;
        std::cin.ignore();
        if (cin.get() == 'q') break;
    }
    
    cout << "Press ENTER to continue..." << endl;
    std::cin.ignore();
    system("clear");
    return 0;
}

