#ifndef BUYER_H
#define BUYER_H

#include <string>


class Buyer {

private:
    std::string buyer_name;
    int buyer_id;


public:
    
    // Get info
    Buyer(std::string buyer_name, int buyer_id);
    void print_buyer_info();
    std::string get_buyer_name();
    int get_buyer_id();

    // Set info
    void set_buyer_name(std::string buyer_name);

};


#endif