#pragma once
#ifndef JSON_DEF_H
#define JSON_DEF_H

#include "../../lib/nlohmann/json.hpp"
#include <string>
#include <unordered_map>

using namespace std;
using json = nlohmann::json;

json json_objs(string key);

#endif // JSON_DEF_H