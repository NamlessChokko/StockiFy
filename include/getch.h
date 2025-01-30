#pragma once
#ifndef GETCH_H
#define GETCH_H

// This code is IA generated using Deep Seek's DeepSeek-V3 model.
// Model version: DeepSeek-V3
// Date: 01/29/2025

// Prompt: 
// Puedes darme el codigo de un Header que me de una funcion que  
// pause el flujo del programa y espere un input. Y que, cuando se 
// presione una tecla, se retorne la tecla que se presiono y devuelva 
// el flujo sin necesidad de presionar enter.

// Prompt translated to English:
// Can you give me the code of a Header that gives me a function that
// pauses the program flow and waits for an input, and that when a key is
// pressed, the key that was pressed is returned and the flow returns without
// needing to press enter.


#include <iostream>

#ifdef _WIN32
    #include <conio.h>  
#else
    #include <termios.h> 
    #include <unistd.h>
#endif

char getch() {
#ifdef _WIN32
    return _getch();
#else
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt); 
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); 
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); 
    ch = getchar(); 
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    return ch;
#endif
}

#endif // GETCH_H