#pragma once
#ifndef OPTION_MENU_C_H
#define OPTION_MENU_C_H

#include <string>
#include <vector>


class Option_Menu {
    private:
        std::string menu_name;
        std::string menu_title;
        std::string menu_subtitle;
        std::string menu_body_paragraph;
        int options_count;
        std::vector<std::string> options;

    public:
        Option_Menu();
        ~Option_Menu();

        void set_menu_name(std::string _menu_name);
        void set_menu_title(std::string _menu_title);
        void set_menu_subtitle(std::string _menu_subtitle);
        void set_menu_body_paragraph(std::string _menu_body_paragraph);
        void set_options_count(int _options_count);
        void set_options(std::string quote, int index);

        std::string get_menu_name();
        std::string get_title();
        std::string get_subtitle();
        std::string get_body_paragraph();
        int get_options_count();
        std::string get_options(int index);

        void clean_menu();
};



#endif