#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>
#include <optional>


class Purchase {

private:
    int purchase_id;
    std::string item_name;
    double price;
    int item_id;
    int seller_id;
    int buyer_id;

public:

    // Constructor
    Purchase(int _purchase_id, std::string _item_name, double _price, int _item_id, int _seller_id, int _buyer_id);
    
    // Print Info
    void print_purchase_info();

    // Get Info
    int get_purchase_id();
    std::string get_item_name();
    double get_price();
    int get_item_id();
    int get_seller_id();
    int get_buyer_id();


    // Modify item
    void remove_purchase();

};


#endif