#pragma once
#ifndef PRINTF_UNCTIONS_H
#define PRINTF_UNCTIONS_H

#include <string>

void printL(string input, string color, int width, bool has_border);

void printC(string input, string color, int width);

void Option_menu(
    menu menu
);

void Input_menu(
    menu menu
);

void Info_menu(
    menu menu
);

void Error_screen(int error_code);

int initOpt(
    menu menu 

);

string input (
    string _prompt, 
    string input_name,
    string key,
    int minimum_length,
    int maximum_length,
    bool start_space,
    bool end_space
);


#endif // PRINTF_UNCTIONS_H