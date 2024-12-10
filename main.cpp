/*
 *
*/

#include "user_interface.hpp"
#include "node.hpp"
#include "parser.hpp"
#include "calculator.hpp"
using std::string;

int main() {
    while (true) {
        string inputExpression = input();
        Parser parser;
        Node* computeTree = parser.create_tree(inputExpression);
        float result = Calculator::calculate(computeTree);
        output_result(std::to_string(result));
        
    }
}
