#pragma once
#ifndef INPUT_MINI_MENU_C_H
#define INPUT_MINI_MENU_C_H

#include <string>
#include <vector>

using namespace std;


class minInput_Menu {
private:
    string name;
    string title;
    string subtitle;
    string body_paragraph;
    string input_name;
    int requirements_count;
    vector<string> input_requirements;

public:

    minInput_Menu();

    void set_title(string new_title);
    void set_subtitle(string new_subtitle);
    void set_body_paragraph(string new_body_paragraph);
    void set_input_name(string new_input_name);
    void set_requirements_count(int new_count);
    void set_input_requirements(string quote, int index);

    string get_title();
    string get_subtitle();
    string get_body_paragraph();
    string get_input_name();
    int get_requirements_count();
    string get_input_requirement(int index);

    void clean_data();

};


#endif