#include "include/product/Item.h"
#include <iostream>
#include <string>
#include <optional>

using namespace std;

// Constructor with underscore parameters:
Item::Item(string _item_name, double _price, int _item_id, int _seller_id)
{
    item_name = _item_name;
    price = _price;
    item_id = _item_id;
    seller_id = _seller_id;
}


// Print Info
void Item::print_item_info(){
    cout << "Item Name: " << item_name << std::endl;
    cout << "Price: " << price << std::endl;
    cout << "Item ID: " << item_id << std::endl;
    cout << "Seller ID: " << seller_id << std::endl;

}


// Get Info
string Item::get_item_name(){
    return item_name;

}

double Item::get_price(){
    return price;

}

int Item::get_item_id(){
    return item_id;

}

int Item::get_seller_id(){
    return seller_id;

}


// Set Info
int Item::set_price (double new_price){
    int error_code = 0;
    price = new_price;

    return error_code;
}


// Modify Item
void Item::destroy_item(){
    item_name = "";
    price = 0;
    item_id = 0;
    seller_id = 0;

}


//TODO: Finish price verification in set_price()
//TODO: General util function to print info 