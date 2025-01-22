#include "include/events/Purchase.h"
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