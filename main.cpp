#include "user_interface.hpp"
#include "node.hpp"
#include "parser.hpp"
#include "calculator.hpp"
using namespace std;

int main() {
    while (true) {
        // Get the user's input
        string input_expression = input();

        // Validate the input has no invalid characters.
        if (!validate_input(input_expression)) {
            cout << "Please try again. Invalid characters in expression." << endl;
            continue;
        }

        // Create a parser object and create the computation tree.
        Parser parser;
        Node* computeTree = parser.create_tree(input_expression);

        // Calculate the result and output it.
        float result = Calculator::calculate(computeTree);
        output_result(std::to_string(result));
        
    }
}
