#pragma once
#ifndef JSON_U_H
#define JSON_U_H

#include <optional>
#include <string>
#include "../lib/nlohmann/json.hpp"


std::string get_string(std::string key, std::string file_path);

std::string read_error_message(int error_number, std::string file_path);


#endif // JSON_U_H