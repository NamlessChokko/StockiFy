#include "../../include/Menu.h"


using namespace std;

menu::menu(){
    clean_data();
};

void menu::set_title(string new_title){
    title = new_title;
};
void menu::set_subtitle(string new_subtitle){
    subtitle = new_subtitle;
};
void menu::set_body_paragraph(string new_body_paragraph){
    
    body_paragraph = new_body_paragraph;
};
void menu::set_options_count(int new_options_count){
    options_count = new_options_count;
    options.resize(options_count);
    options_keys.resize(options_count);
    options_descriptions.resize(options_count);
};
void menu::set_options(string quote, int index){
    options[index] = quote;
};
void menu::set_options_keys(char key, int index){
    options_keys[index] = key;
};
void menu::set_option_description(string new_option_description, int index){
    options_descriptions[index] = new_option_description;
};
void menu::set_requirement_count(int new_requirement_count){
    requirement_count = new_requirement_count;
    input_requirements.resize(requirement_count);
};
void menu::set_input_name(string new_input_name){
    input_name = new_input_name;
};
void menu::set_input_requirements(string quote, int index){
    input_requirements[index] = quote;
};

void menu::set_information_prompt(string new_prompt){
    information_prompt = new_prompt;
}

void menu::set_information_name(string new_info_name){
    information_name = new_info_name;
};

void menu::set_information(string new_information){
    information = new_information;
}

string menu::get_name(){
    return name;
};
string menu::get_title(){
    return title;
};
string menu::get_subtitle(){
    return subtitle;
};
string menu::get_body_paragraph(){
    return body_paragraph;
};
int menu::get_options_count(){
    return options_count;
};
string menu::get_option(int index){
    return options[index];
};
char menu::get_option_key(int index){
    return options_keys[index];
};
string menu::get_option_description(int index){
    return options_descriptions[index];
};
int menu::get_requirement_count(){
    return requirement_count;
};
string menu::get_input_name(){
    return input_name;
};
string menu::get_input_requirement(int index){
    return input_requirements[index];
};

string menu::get_information_name(){
    return information_name;
};

string menu::get_information_prompt(){
    return information_name;
};

string menu::get_information(){
    return information;
};

void menu::clean_data(){ 
    name = "";
    title = "";
    subtitle = "";
    body_paragraph = "";
    options_count = 3;
    options.clear();
    options_keys.clear();
    options_descriptions.clear();
    requirement_count = 3;
    input_name = "";
    input_requirements.clear();

};