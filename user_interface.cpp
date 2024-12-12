/*
 * Contains functions to gather input strings from 
 * the user, as well as display output strings.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;


// Takes in a string and removes all spaces, manipulating
// the string in place.
void remove_spaces(string& str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            str.erase(i, 1);
            i--;
        }
    }
}

// Validates that the input is a valid operator
bool is_operator(char input) {
    if (input == '+' || input == '-' || input == '*' || input == '/' || input == '(' || input == ')' || input == '%') {
        return true;
    } else {
        return false;
    }
}

// Validates there are no invalid characters in the input
bool validate_input(string input) {
    for (int i = 0; i < input.length(); i++) {
        if (is_operator(input[i]) || isdigit(input[i])) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

// Ask the user for an expression to evaluate and return it as a string,
// with spaces removed.
string input() {
    cout << endl << "Enter the expression you would like to evaluate: ";
    string expression;
    getline(cin, expression);
    remove_spaces(expression);
    return expression;
}

// Takes in a result and displays it to the user.
void output_result(string result) {
    cout << "The result is: ";
    cout << fixed;
    cout << setprecision(2);
    cout << result << "\n";
}

// Outputs the error message passed in.
void output_error(string error_message) {
    cout << "Error: " << error_message << "\n\n";
}
