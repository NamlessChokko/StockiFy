#include "../include/Utils.h"
#include <string>
#include <optional>
#include <iostream>

using namespace std;


optional<int> select_option (
    int number_of_options = 3
){
    int option;

    try{
        cin >> option;
    }
    catch (exception& e){   
        return nullopt;
    }

    if (option < 1 || option > number_of_options){
        return nullopt;
    }

    return option;

}