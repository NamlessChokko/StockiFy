#include "../../include/Input_Menu_c.h"
#include <string> 

using namespace std;


Input_Menu::Input_Menu(){
    clean_data();
};


void Input_Menu::set_title(string new_title){
    title = new_title;
};

void Input_Menu::set_subtitle(string new_subtitle){
    subtitle = new_subtitle; 
};

void Input_Menu::set_body_paragraph(string new_body_paragraph){
    body_paragraph = new_body_paragraph;
};

void Input_Menu::set_input_name(string new_name){
    input_name = new_name;
};

void Input_Menu::set_requirements_count(int new_count){
    requirements_count = new_count;
    input_requirements.resize(requirements_count);
};

void Input_Menu::set_input_requirements(string quote, int index){
    input_requirements[index] = quote;
};


string Input_Menu::get_title(){return title;}

string Input_Menu::get_subtitle(){return subtitle;}

string Input_Menu::get_body_paragraph(){return body_paragraph;}

string Input_Menu::get_input_name(){return input_name;}

int Input_Menu::get_requirements_count(){return requirements_count;}

string Input_Menu::get_input_requirement(int index){return input_requirements[index];}


void Input_Menu::clean_data(){
    name = "";
    title = "";
    subtitle = "";
    body_paragraph = "";
    input_name = "";
    requirements_count = 0;
    input_requirements.resize(requirements_count);

};