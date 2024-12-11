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
            output_error("Invalid characters in expression.");
            continue;
        }

        Node* computeTree;
        string error_message;

        try {
            // Create a parser object and create the computation tree.
            Parser parser;
            tie(computeTree, error_message) = parser.create_tree(input_expression);
        }
        catch (const std::exception& e) {
            output_error("Invalid expression.");
            continue;
        }

        if (error_message != "") {
            output_error(error_message);
            continue;
        }

        // Calculate the result and output it.
        float result = Calculator::calculate(computeTree);
        output_result(std::to_string(result));
        
    }
}
