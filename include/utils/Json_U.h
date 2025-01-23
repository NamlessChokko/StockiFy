#ifndef JSON_U_H
#define JSON_U_H

#include <optional>
#include <string>
#include <fstream>

#include "../../lib/nlohmann/json.hpp"

std::optional<std::string> get_string(std::string file_path, std::string key);

std::optional<std::string> read_error_message(std::string file_path, std::string erro_type, std::string key);


#endif