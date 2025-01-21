#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <optional>


class Item {

private:
    std::string item_name;
    double price;
    int item_id;
    int seller_id;


public:

    // Constructor
    Item(std::string item_name, double price, int item_id, int seller_id);
    
    // Print Info
    void print_item_info();

    // Get Info
    std::string get_item_name();
    double get_price();
    int get_item_id();
    int get_seller_id();

    // Set info
    int set_price(double new_price);

    // Modify item
    void destroy_item();

};

#endif 