#ifndef CLIENT_H
#define CLIENT_H

#include <string>


class Client {

private:
    int client_id; 
    std::string client_name;
    std::string client_description;
    bool is_seller;


public:

    // Constructor:
    Client(std::string _client_name, bool _is_seller);

    // Print info:
    void print_client_info();

    // Get info:
    int get_client_id();
    std::string get_client_name();
    std::string get_client_description();
    bool is_client_seller();
    
    // Set info:
    bool set_client_name(std::string _new_name);
    bool set_client_description(std::string _new_description);
    bool set_seller_in(bool _new_seller_state);

    // Modify client:
    void clean_client_info();

};


#endif