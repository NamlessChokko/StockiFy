#include "../include/StockiFy.h"
#include <string.h>
#include <iostream>

using namespace std;

int main (){
    Client client1("John Doe", false); // Create a client object with name John Doe and seller status false
    client1.print_client_info(); // Print the client info


    // Client info is changed 
    client1.set_client_name("Manuel Ortega");
    client1.set_client_description("This is a test description");
    client1.set_seller_in(true);

    // Print client info again
    client1.print_client_info();


    return 0;
}