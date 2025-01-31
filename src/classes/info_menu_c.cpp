#include "../include/Info_Menu_c.h"
#include <string>

using namespace std;


Info_Menu::Info_Menu(){
    Info_Menu::clean_information();
};

void Info_Menu::set_name(string new_name){
    name = new_name;
};

void Info_Menu::set_title(string new_title){
    title = new_title;
};

void Info_Menu::set_subtitle(string new_subtitle){
    subtitle = new_subtitle;
};

void Info_Menu::set_body_paragraph(string new_body_paragraph){
    body_paragraph = new_body_paragraph;
};

void Info_Menu::set_information_name(string new_information_name){
    information_name = new_information_name;
};

void Info_Menu::set_information(string new_information){
    information = new_information;
};


string Info_Menu::get_title(){
    return title;
};

string Info_Menu::get_subtitle(){
    return subtitle;
};

string Info_Menu::get_body_paragraph(){
    return body_paragraph;
};

string Info_Menu::get_information_name(){
    return information_name;
};

string Info_Menu::get_information(){
    return  information;
};


void Info_Menu::clean_information(){
    name = "";
    title = "";
    subtitle = "";
    body_paragraph = "";
    information_name = "";
    information = "";
}