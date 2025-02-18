#pragma once
#ifndef PRINTF_UNCTIONS_H
#define PRINTF_UNCTIONS_H

#include "Menu.h"
#include "Definitions.h"
#include "Menu_Interactions.h"
#include "Strings_u.h"
#include "Terminal_u.h"
#include "Math_u.h"
#include "Json_u.h"
#include <iostream>
#include <string>
#include <format>
#include <vector>

using namespace std;


void prtLL(string input, string color, int width, int number_lines, bool has_border);

void printL(string input, string color, size_t width, bool has_border);

void printC(string input, string color, size_t width, bool has_border);

int initOpt (menu menu);

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