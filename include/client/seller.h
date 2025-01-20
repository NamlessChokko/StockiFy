#ifndef SELLER_H
#define SELLER_H

#include <string>


class Seller {

private:
    std::string seller_name;
    std::string seller_description;
    int seller_id;

public:

    // Get info
    Seller(std::string seller_name, std::string seller_description, int seller_id);
    void print_seller_info();
    std::string get_seller_name();
    int get_seller_id();
    std::string get_seller_description();

    // Set info
    void set_seller_name(std::string seller_name);
    void set_seller_description(std::string seller_description);

};

#endif