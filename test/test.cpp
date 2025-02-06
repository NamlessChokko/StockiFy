#include "../include/StockiFy.h"
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <unistd.h>



using namespace std;

int main (){
    system("clear");
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    cout << bl << "Current working dir: " << rst << cwd << endl;
    cout << endl;

    while (1){
        cout << ">>> "; 
        char arrow = get_arrow();
        cout << "Your pressed: " << arrow << endl; 
    }

    // cin.ignore();
    cout << rst;
    system("clear");
    cout << rst << bg_bk;
    return 0;
}

