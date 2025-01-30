#pragma once
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

    Item(std::string _item_name, double _price, int _item_id, int _seller_id);
    
    void print_item_info();

    std::string get_item_name();
    double get_price();
    int get_item_id();
    int get_seller_id();

    bool set_price(double _new_price);

    bool destroy_item();

};

#endif 