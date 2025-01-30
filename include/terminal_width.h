#ifndef TERMINAL_WIDTH_H
#define TERMINAL_WIDTH_H

#ifdef _WIN32
    #include <windows.h>
#else
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

int getTerminalWidth() {
    int width = 80; 

    #ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
            width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        }
    #else
        struct winsize size;
        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) == 0) {
            width = size.ws_col;
        }
    #endif

    return width;
}

#endif // TERMINAL_WIDTH_H