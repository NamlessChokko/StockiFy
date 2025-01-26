#include "../../../include/events/Purchase.h"
#include <iostream>
#include <string>

using namespace std;


// Constructor
Purchase::Purchase(int _purchase_id, string _item_name, double _price, int _item_id, int _seller_id, int _buyer_id) {
    purchase_id = _purchase_id;
    item_name = _item_name;
    price = _price;
    item_id = _item_id;
    seller_id = _seller_id;
    buyer_id = _buyer_id;

}


// Print Info
void Purchase::print_purchase_info() {
    cout << "Purchase ID: " << purchase_id << endl;
    cout << "Item Name: " << item_name << endl;
    cout << "Price: " << price << endl;
    cout << "Item ID: " << item_id << endl;
    cout << "Seller ID: " << seller_id << endl;
    cout << "Buyer ID: " << buyer_id << endl;

}


// Get Info
int Purchase::get_purchase_id() {

    return purchase_id;
}

string Purchase::get_item_name() {

    return item_name;
}

double Purchase::get_price() {

    return price;
}

int Purchase::get_item_id() {

    return item_id;
}

int Purchase::get_seller_id() {

    return seller_id;
}

int Purchase::get_buyer_id() {

    return buyer_id;
}


// Modify item
void Purchase::remove_purchase() {
    purchase_id = 0;
    item_name = "";
    price = 0;
    item_id = 0;
    seller_id = 0;
    buyer_id = 0;
    
}