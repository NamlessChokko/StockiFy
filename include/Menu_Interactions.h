#pragma once
#ifndef MENU_INTERACTIONS_H
#define MENU_INTERACTIONS_H

#include <optional>
#include <string>

std::string error_handler (int error_number);

std::optional<int> select_option (int number_of_options);

char get_arrow ();

int getKey();


#endif // MENU_INTERACTIONS_H