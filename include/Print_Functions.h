#pragma once
#ifndef PRINTF_UNCTIONS_H
#define PRINTF_UNCTIONS_H

#include <string>

void printL(string input, string color, int width);

void printC(string input, string color, int width);

void Option_menu(
    Option_Menu menu
);

void Input_menu(
    Input_Menu menu
);

void Info_menu(
    Info_Menu menu
);

void Error_screen(int error_code);

void dynamic_option_menu(
    menu menu 

);


#endif // PRINTF_UNCTIONS_H