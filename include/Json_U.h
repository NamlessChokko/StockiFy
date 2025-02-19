#pragma once
#ifndef JSON_U_H
#define JSON_U_H

#include "Json_def.h"
#include "Definitions.h"
#include "../../lib/nlohmann/json.hpp"
#include <string>
#include <optional>
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
using json = nlohmann::json;
namespace fs = filesystem; 

string get_value(string key, string file_path);

string read_error_message(int error_number, string file_path);

string makeFile_s (string name, string dir);

int enter_obj (string file_path, string obj);


#endif // JSON_U_H