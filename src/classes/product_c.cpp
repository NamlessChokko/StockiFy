#include "include/Product.h"
#include <iostream>

// Constructor:
Product::Product(std::string product_name, double price, int product_id, int seller_id)
{
    product_name = product_name;
    price = price;
    product_id = product_id;
    seller_id = seller_id;

}

// Get info methods
void Product::print_product_info()
{
    std::cout << "Product Name: " << product_name << std::endl;
    std::cout << "Description: " << product_description << std::endl;
    std::cout << "Product ID: " << product_id << std::endl;
    std::cout << "Amount: " << product_amount << std::endl;

}

std::string Product::get_product_name()
{
    return product_name;
}

int Product::get_product_id()
{
    return product_id;
}