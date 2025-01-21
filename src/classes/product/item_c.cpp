#include "include/product/Item.h"
#include <iostream>
#include <string>
#include <optional>

using namespace std;


// Constructor:
Item::Item(string item_name, double price, int item_id, int seller_id)
{
    item_name = item_name;
    price = price;
    item_id = item_id;
    seller_id = seller_id;

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


//TODO: Finish price verification in set_price()
//TODO: General util function to print info 