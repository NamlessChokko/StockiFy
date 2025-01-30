#include "../include/StockiFy.h"
#include <string.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main (){
    system("clear");
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    cout << "Current working dir: " << cwd << endl;

    string test = "";

    test = format("This is a ^gntest*rs. I am using my ^blown*rs #wt^blformating system*rs. If this ^rdwork*rs, #gn^bkI will*rs ^gnsleep*rs.");
    cout << test << endl;   


    cout << "Press ENTER to continue..." << endl;
    std::cin.ignore();
    system("clear");
    return 0;
}

