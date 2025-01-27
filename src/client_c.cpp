#include "../include/Client.h"
#include "../include/Strings_u.h"
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
bool Client::set_client_name(string _new_name){

    optional<string> optNew_name = valid_string(_new_name, 3, 15, "client_name", false, false);

    if (!optNew_name.has_value()){
        return false;
    }

    client_name = optNew_name.value(); 
    return true;
}

bool Client::set_client_description(string _new_description){

    optional<string> optNew_description = valid_string(_new_description, 0, 50, "client_description", false, true);

    if (!optNew_description.has_value()){
        return false;
    }

    client_description = optNew_description.value();
    return true;
}

bool Client::set_seller_in(bool _new_seller_state){

    is_seller = _new_seller_state;
    return true;
}


// Modify Client
void Client::destroy_client(){
    client_id = 0;
    client_name = "";
    client_description = "";
    is_seller = false;

}



//TODO: Finish set_seller validation