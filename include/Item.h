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

    // Constructor
    Item(std::string _item_name, double _price, int _item_id, int _seller_id);
    
    // Print Info
    void print_item_info();

    // Get Info
    std::string get_item_name();
    double get_price();
    int get_item_id();
    int get_seller_id();

    // Set info
    bool set_price(double _new_price);

    // Modify item
    bool destroy_item();

};

#endif 