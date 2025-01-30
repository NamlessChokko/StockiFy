#pragma once
#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <string>
#include <optional>

std::string error_handler (std::string error_type, int error_number, std::string file_path);

#endif // ERROR_HANDLER_H