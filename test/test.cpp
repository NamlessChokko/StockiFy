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

    Info_Menu menu;
    menu.set_title("Main Menu");
    menu.set_subtitle("Welcome to testing screen");
    menu.set_body_paragraph("This program is a test of functions that bla bla bla because the demand of pollos is increasing cuz the immigrants and we dont have access to de information given by the baby shark tu tu dudu tutu.");
    menu.set_information_name("Information name");
    menu.set_information("Important Information");

    Info_menu(menu, cn);

    cin.ignore();
    cout << rst;
    system("clear");
    cout << rst << bg_bk;
    return 0;
}

