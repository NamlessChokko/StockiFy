#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>


class Product {

private:
    std::string product_name;
    std::string product_description;
    int product_id;
    int product_amount;


public:

    // Get info
    Product(std::string product_name, double price, int product_id, int seller_id);
    void print_product_info();
    std::string get_product_name();
    int get_product_id();
    int get_product_amount();


};


#endif