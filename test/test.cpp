#include "../include/StockiFy.h"
#include <string.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main (){
    system("clear");
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    cout << bl << "Current working dir: " << rst << cwd << endl;

    Item item1;
    cout << yl;
    item1.print_item_info();
    cout << rst;

    cout << mg << "Changing initial values to correct values: " << rst << endl;
    cout << "Setting item name to " << gn << "'Item1'" << rst << "..."  << endl;
    item1.set_item_name("Item1");
    cout << "Setting item description to " << gn <<"'This is a test item.'" << rst << "..." << endl;
    item1.set_item_description("This is a test item");
    cout << "Setting price to " << gn << "10.99" << rst << "..." << endl;
    item1.set_price(10.99);

    cout << "New client name: ";
    cout << gn << item1.get_item_name() << rst << endl;
    cout << "New client description: ";
    cout << gn << item1.get_item_description() << rst << endl;
    cout << "New client price: ";
    cout << gn << item1.get_price() << rst << endl;

    cout << mg << "Changing values to invalid values: " << rst << endl;
    cout << "Setting item name to " << rd << "'Invalid name \\'" << rst << "..." << endl;
    item1.set_item_name("Invalid name \\");
    cout << "Setting item description to " << rd << "' Invalid Description /|~'" << rst << "..." << endl;
    item1.set_item_description(" Invalid Description /|~");


    cout << "New client name: ";
    cout << rd << item1.get_item_name() << rst << endl;
    cout << "New client description: ";
    cout << rd << item1.get_item_description() << rst << endl;



    cout << "Press " << bl <<"ENTER " << rst << "to continue..." << endl;
    std::cin.ignore();
    system("clear");
    return 0;
}

