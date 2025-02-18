#pragma once
#ifndef MENU_INTERACTIONS_H
#define MENU_INTERACTIONS_H

#include "Terminal_u.h"
#include "Json_u.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;


string error_handler (int error_number);

int validate_option (
    char input,
    int number_of_options,
    vector<char> options 
);

char get_arrow ();

int getKey();


#endif // MENU_INTERACTIONS_H