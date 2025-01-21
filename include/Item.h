#ifndef ITEM_H
#define ITEM_H

#include <string>


class Item {

private:
    std::string item_name;
    double price;
    int item_id;
    int seller_id;

public:

    // Get info
    Item(std::string item_name, double price, int item_id, int seller_id);
    void print_item_info();
    std::string get_item_name();
    double get_price();
    int get_item_id();
    int get_seller_id();

    // Set info
    void set_price(double price);

    // Modify item
    void destroy_item();

};

#endif 