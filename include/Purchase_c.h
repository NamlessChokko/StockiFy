#pragma once
#ifndef PURCHASE_H
#define PURCHASE_H

#include <iostream>
#include <string>


class Purchase {

private:
    int purchase_id;
    std::string item_name;
    double price;
    int item_id;
    int seller_id;
    int buyer_id;

public:

    Purchase(int _purchase_id, std::string _item_name, double _price, int _item_id, int _seller_id, int _buyer_id);
    
    void print_purchase_info();

    int get_purchase_id();
    std::string get_item_name();
    double get_price();
    int get_item_id();
    int get_seller_id();
    int get_buyer_id();

    bool remove_purchase();

};


#endif // PURCHASE_H