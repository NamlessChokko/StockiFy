#pragma once
#ifndef PRINTF_UNCTIONS_H
#define PRINTF_UNCTIONS_H

#include <string>

void printL(string input, string color, int width);

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

int dynamic_option_menu(
    menu menu 

);


#endif // PRINTF_UNCTIONS_H