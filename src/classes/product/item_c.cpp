#include "include/Item.h"
#include <iostream>

// Constructor:
Item::Item(std::string item_name, double price, int item_id, int seller_id)
{
    item_name = item_name;
    price = price;
    item_id = item_id;
    seller_id = seller_id;

}

// Get info methods
void Item::print_item_info()
{
    std::cout << "Item Name: " << item_name << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Item ID: " << item_id << std::endl;
    std::cout << "Seller ID: " << seller_id << std::endl;

}

// Set info methods
void Item::set_price(double price)
{
    price = price;
}