#include "../../include/Client_c.h"
#include "../../include/Strings_u.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor
Client::Client(){
    clean_client_info();

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
bool Client::set_client_name(string new_name){ 
    
    if (!is_valid_string(new_name,"client_name", 3, 50, false, false)){
        return false;
    }

    client_name = new_name; 
    return true;
}

bool Client::set_client_description(string new_description){
    

    if (!is_valid_string(new_description, "client_description", 0, 200, false, true)){
        return false;
    }

    client_description = new_description;
    return true;
}

bool Client::set_seller_in(bool new_seller_state){

    is_seller = new_seller_state;
    return true;
}


// Modify Client
void Client::clean_client_info(){
    client_id = 0001;
    client_name = "";
    client_description = "";
    is_seller = false;

}



//TODO: Finish set_seller validation