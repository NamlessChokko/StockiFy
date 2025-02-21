#pragma once
#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;


class menu {
private:
    string name;
    string title;
    string subtitle;
    string body_paragraph;

    int options_count;
    vector<string> options;
    vector<char> options_keys;
    vector<string> options_descriptions;

    int requirement_count;
    string input_name;
    vector<string> input_requirements;

    string information_prompt;
    string information;
    string information_name;

public:
    menu();

    void set_title(string new_title);
    void set_subtitle(string new_subtitle);
    void set_body_paragraph(string new_body_paragraph);
    void set_options_count(int new_options_counter);
    void set_options(string quote, int index);
    void set_options_keys(char key, int index);
    void set_option_description(string new_option_description, int index);
    void set_requirement_count(int new_requirement_count);
    void set_input_name(string new_input_name);
    void set_input_requirements(string quote, int index);
    void set_information_prompt(string new_information_prompt);
    void set_information_name(string new_information_name);
    void set_information(string new_information);

    string get_name();
    string get_title();
    string get_subtitle();
    string get_body_paragraph();
    int get_options_count();
    string get_option(int index);
    char get_option_key(int index);
    string get_option_description(int index);
    int get_requirement_count();
    string get_input_name();
    string get_input_requirement(int index);
    string get_information_prompt();
    string get_information_name();
    string get_information();

    void clean_data();

};


#endif // MENU_H