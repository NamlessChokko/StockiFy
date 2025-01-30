#include "../../include/Item_c.h"
#include "../../include/Strings_u.h"
#include <iostream>
#include <string>
#include <optional>

using namespace std;


Item::Item(){
    clean_item_info();
}

Item::~Item(){
    clean_item_info();
}

void Item::print_item_info(){
    cout << "Item Name: " << item_name << endl;
    cout << "Item Description: " << item_description << endl;
    cout << "Price: " << price << endl;
    cout << "Item ID: " << item_id << endl;
    cout << "Seller ID: " << seller_id << endl;

}


string Item::get_item_name(){

    return item_name;
}

string Item::get_item_description(){

    return item_description;
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


int Item::set_item_name(string new_item_name){
    int error_code;
    
    error_code = is_valid_string(new_item_name, "item_name", 3, 100, false, false);

    item_name = (error_code == 0)? new_item_name : item_name;
    return error_code;
}

int Item::set_item_description(string new_item_description){
    int error_code;
    
    error_code = is_valid_string(new_item_description, "item_description", 3, 100, false, true);

    item_description = (error_code == 0)? new_item_description : item_description;
    return error_code;
}

int Item::set_price (double new_price){
    price = new_price;

    return true;
}


bool Item::clean_item_info(){
    item_name = "";
    item_description = "";
    price = 0;
    item_id = 0;
    seller_id = 0;

    return true;
}


//TODO: Finish price verification in set_price()
