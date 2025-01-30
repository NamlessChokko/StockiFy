#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <string>


class Item {

private:
    std::string item_name;
    std::string item_description;
    double price;
    int item_id;
    int seller_id;


public:

    Item();
    ~Item();
    
    void print_item_info();

    std::string get_item_name();
    std::string get_item_description();
    double get_price();
    int get_item_id();
    int get_seller_id();

    int set_item_name(std::string _item_name);
    int set_item_description(std::string _item_description);
    int set_price(double _new_price);

    bool clean_item_info();

};

#endif // ITEM_H