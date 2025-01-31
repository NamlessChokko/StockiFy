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

    cout << getTerminalWidth() << endl;


    cout << "Press " << bl <<"ENTER " << rst << "to continue..." << endl;
    std::cin.ignore();
    system("clear");
    return 0;
}

