#include "../include/Error_Handler.h"
#include "../include/Json_U.h"
#include <string>
#include <optional>

using namespace std;
const string default_file_path = "json_db/expected_errors.json";


string error_handler (
    string error_type,
    int error_number,
    string file_path = default_file_path

){

    optional<string> error_message = read_error_message(file_path, error_type, error_number);

    if (error_message.has_value()){
        return error_message.value();
    }

    return "An unexpected error occurred. Please, check directory json_db/expected_errors.json";

}