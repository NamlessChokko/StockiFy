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


    menu menu1;
    menu1.set_title("StockiFy");
    menu1.set_subtitle("Select an option:");
    menu1.set_body_paragraph("Welcome to StockiFy! Here you can manage your stocks.");
    menu1.set_options_count(2);
    menu1.set_options("Enter", 0);
    menu1.set_options("Setting", 1);
    menu1.set_option_description("Enter and use the program pppppppppppppppppppppppppppppp", 0);
    menu1.set_option_description("Change the program's settings ssssssssssssssssssssssssssssssssssss", 1);

    dynamic_option_menu(menu1);
    
    cin.ignore();
    cout << rst;
    system("clear");
    cout << rst << bg_bk;
    return 0;
}

