/*
 * Contains functions to gather input strings from 
 * the user, as well as display output strings.
 */

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;


/*
 * Takes in a string and removes all spaces, manipulating
 * the string in place.
 */
void removeSpaces(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            str.erase(i, 1);
            i--;
        }
    }
}

/*
 * Ask the user for an expression to evaluate and return it as a string,
 * with spaces removed.
 */
string input() {
    cout << "Enter the expression you would like to evaluate: ";
    string expression;
    std::getline(cin, expression);
    return expression;
}

/*
 * Takes in a result and displays it to the user.
 */
void output_result(string result) {
    cout << "The result is: " << result << "\n";
}
