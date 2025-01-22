#include "include/client/Client.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor
Client::Client(string _client_name, bool _is_seller){
    client_id = 0001;
    client_name = _client_name;
    client_description = "Empty";
    is_seller = _is_seller;
}


 // Print Info:
void Client::print_client_info(){
    cout << "Client id: " << client_id << endl;
    cout << "Client name: " << client_name << endl;
    cout << "Client description: " << client_description << endl;
    cout << "Is client seller: " << is_seller << endl; 

}


// Get Info:
int Client::get_client_id(){

    return client_id;
}

string Client::get_client_name(){

    return client_name;
}

string Client::get_client_description(){

    return client_description;
}

bool Client::is_client_seller(){

    return is_seller;
}


// Set Info:
int Client::set_client_name(string new_name){
    bool error_code = 0;

    if (new_name.empty()){
        error_code = 1;

    }

    if (new_name.length() < 4 || new_name.length() > 15){
        error_code = 2;

    }

    if (new_name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != string::npos) {
        error_code = 3;

    }


    client_name = (error_code == 0)? new_name : client_name; 
    return error_code;
}

int Client::set_client_description(string new_description){
    int error_code = 0;

    if (new_description.empty()){
        error_code = 1;

    }

    if (new_description.length() < 6 || new_description.length() > 50){
        error_code = 2;

    }

    if (new_description.find_first_not_of("!@#$&*_-+=123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != string::npos) {
        error_code = 3;

    }

    client_description = (error_code == 0)? new_description : client_description;
    return error_code;
}

int Client::set_seller_in(bool new_seller_state){
    int error_code = 0;


    is_seller = new_seller_state;
    return error_code;
}


// Modify Client
void Client::destroy_client(){
    client_id = 0;
    client_name = "";
    client_description = "";
    is_seller = false;

}


//TODO: Create function to validate strings
//TODO: Define fixed constant with allowed characters
//TODO: Finish set_seller validation