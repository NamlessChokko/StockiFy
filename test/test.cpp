#include "../include/StockiFy.h"

int main(int argc, char *argv[]) {

    system("clear");
    string equal = (compare_file("text.txt", "First line \nSecond line \nThird line"))? "^gnFile is correct!" : "^rdFile is not correct!";  
    cout << format(equal) << rst << endl;



    return 0; 
}