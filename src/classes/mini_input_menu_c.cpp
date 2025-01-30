#include "../../include/Mini_Input_Menu_c.h"
#include <string> 

using namespace std;


minInput_Menu::minInput_Menu(){
    clean_data();
};


void minInput_Menu::set_title(string new_title){
    title = new_title;
};

void minInput_Menu::set_subtitle(string new_subtitle){
    subtitle = new_subtitle; 
};

void minInput_Menu::set_body_paragraph(string new_body_paragraph){
    body_paragraph = new_body_paragraph;
};

void minInput_Menu::set_input_name(string new_name){
    input_name = new_name;
};

void minInput_Menu::set_requirements_count(int new_count){
    requirements_count = new_count;
    input_requirements.resize(requirements_count);
};

void minInput_Menu::set_input_requirements(string quote, int index){
    input_requirements[index] = quote;
};


string minInput_Menu::get_title(){return title;}

string minInput_Menu::get_subtitle(){return subtitle;}

string minInput_Menu::get_body_paragraph(){return body_paragraph;}

string minInput_Menu::get_input_name(){return input_name;}

int minInput_Menu::get_requirements_count(){return requirements_count;}

string minInput_Menu::get_input_requirement(int index){return input_requirements[index];}


void minInput_Menu::clean_data(){
    name = "";
    title = "";
    subtitle = "";
    body_paragraph = "";
    input_name = "";
    requirements_count = 0;
    input_requirements.resize(requirements_count);

};