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
    cout << endl;

    //string input = "In a world where words flow endlessly, the ability to neatly structure and format text is essential. Whether it's an article, a story, or a simple paragraph, ensuring readability is key. This function aims to take a continuous stream of words and break it into lines that fit within a specified width, maintaining the integrity of each word. The challenge arises when words stretch beyond the available space, requiring intelligent handling to prevent abrupt breaks. Spaces, punctuation, and line breaks all play a role in crafting a seamless reading experience. Proper implementation guarantees that no word is left stranded, no phrase awkwardly split, and no meaning lost in the process.";
    string input = "     aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    //string input = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa       aaaaaaaaaaaaaaaaaaaaaa";
    
    vector<string> input_formatted = adj_to_width(input);


    cout << cn << "Debugging data: " << rst << endl;
    cout << cn << "Lines: " << rst << input_formatted.size() << endl;
    cout << cn << "Maximum line length: " << rst << input_formatted[0].size() << endl;
    cout << cn << "Minimum line length: " << rst << input_formatted[input_formatted.size() - 1].size() << endl; 
    cout << cn << "Input length: " << rst << input.size() << endl;
    cout << endl;


    cout << mg << "Without formating: " << rst << endl;
    cout << rd << input << rst << endl;

    cout << endl;
    
    cout << mg << "With formating: " << gn << endl;
    for (int i = 0; i < static_cast<int>(input_formatted.size()); i++) {
        cout << input_formatted[i] << endl;
    }
    cout << rst;


    cin.ignore();
    system("clear");
    return 0;
}

