#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <string>


class Client {

private:
    int client_id;
    bool is_seller;

    std::string client_name;
    std::string client_description;

    std::string client_password;
    std::string client_email;


public:

    Client();

    void print_client_info();

    int get_client_id();
    std::string get_client_name();
    std::string get_client_description();
    bool is_client_seller();
    
    bool set_client_name(std::string new_name);
    bool set_client_description(std::string new_description);
    bool set_seller_in(bool new_seller_state);

    void clean_client_info();

};


#endif // CLIENT_H