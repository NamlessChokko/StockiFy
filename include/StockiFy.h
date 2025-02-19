#pragma once
#ifndef STOCKIFY_H
#define STOCKIFY_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include <filesystem>

#include "Client_c.h"
#include "Item_c.h"
#include "Purchase_c.h"
#include "Menu.h"

#include "Json_u.h"
#include "Strings_u.h"
#include "Terminal_u.h"
#include "Json_def.h"
#include "Main_Functions.h"

#include "Menu_Interactions.h"
#include "Definitions.h"
#include "Print_Functions.h"

using namespace std;
using json = nlohmann::json;
namespace fs = std::filesystem; 


#endif // STOCKIFY_H