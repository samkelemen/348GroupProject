#include <string>

using std::string;


// Ask the user for an expression to evaluate and return it as a string,
// with spaces removed.
string input();

// Takes in a result and displays it to the user.
void output_result(string result);

// Validates that the input has no invalid characters
bool validate_input(string input);

// Outputs the error message passed in.
void output_error(string error_message);
