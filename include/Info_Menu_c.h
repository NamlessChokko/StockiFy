#pragma once
#ifndef INFO_MENU_C_H
#define INFO_MENU_C_H

#include <string>


class Info_Menu {
private:
    std::string name;
    std::string title;
    std::string subtitle;
    std::string body_paragraph;
    std::string information_name;
    std::string information;

public:

    Info_Menu();

    void set_name(std::string);
    void set_title(std::string);
    void set_subtitle(std::string);
    void set_body_paragraph(std::string);
    void set_information_name(std::string);
    void set_information(std::string);
    
    std::string get_name();
    std::string get_title();
    std::string get_subtitle();
    std::string get_body_paragraph();
    std::string get_information_name();
    std::string get_information();
    
    void clean_information();

};


#endif // INFO_MENU_C_H