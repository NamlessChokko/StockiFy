#include "../include/StockiFy.h"


int main(int argc, char *argv[]) {
    system("clear");
    init_program();
    cout << "Press ENTER to exit...";
    getchar();
    
    connect_to_database();

    main_menu();

    return 0; 
}