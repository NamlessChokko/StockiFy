#include "../../include/Option_Menu_c.h"
#include <string>
#include <optional>
#include <vector>

using namespace std;


Option_Menu::Option_Menu() {
    menu_name = "";
    menu_title = "";
    menu_subtitle = "";
    menu_body_paragraph = "";
    options_count = 3;
    options.resize(options_count);
}

Option_Menu::~Option_Menu() {}


void Option_Menu::set_menu_name(string _menu_name) {
    menu_name = _menu_name;
}

void Option_Menu::set_menu_title(string _menu_title) {
    menu_title = _menu_title;
}

void Option_Menu::set_menu_subtitle(string _menu_subtitle) {
    menu_subtitle = _menu_subtitle;
}

void Option_Menu::set_menu_body_paragraph(string _menu_body_paragraph) {
    menu_body_paragraph = _menu_body_paragraph;
}

void Option_Menu::set_options_count(int _options_count) {
    options_count = _options_count;
    options.resize(options_count);
}

void Option_Menu::set_options(string quote, int index) {
    options[index] = quote;
}


string Option_Menu::get_menu_name() {
    return menu_name;
}

string Option_Menu::get_title() {
    return menu_title;
}

string Option_Menu::get_subtitle() {
    return menu_subtitle;
}

string Option_Menu::get_body_paragraph() {
    return menu_body_paragraph;
}

int Option_Menu::get_options_count() {
    return options_count;
}

string Option_Menu::get_options(int index) {
    return options[index];
}



