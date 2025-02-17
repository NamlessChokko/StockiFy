#pragma once
#ifndef JSON_DEF_H
#define JSON_DEF_H
#include <string>
#include "../../lib/nlohmann/json.hpp"
using namespace std;
using namespace nlohmann;

json re_allowed_char ();

json re_expected_errors ();

json resettings ();

#endif // JSON_DEF_H