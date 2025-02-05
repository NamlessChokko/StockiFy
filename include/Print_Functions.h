#pragma once
#ifndef PRINTF_UNCTIONS_H
#define PRINTF_UNCTIONS_H

#include <string>

void printL(string input, string color, int width);

void printC(string input, string color, int width);

void Option_menu(
    Option_Menu menu, 
    string border_color = cn
);

void Input_menu(
    Input_Menu menu,
    string border_color = cn
);

void Info_menu(
    Info_Menu menu,
    string border_color = cn
);

void Error_screen(int error_code);


#endif // PRINTF_UNCTIONS_H