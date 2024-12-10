/*
 *
*/

#include "user_interface.h"
#include "node.hpp"
#include "parser.hpp"
using std::string;


int main() {
    while (true) {
        string input = input();
        Node* compute_tree = Parser::create_tree(string expression);
        // float result = calculator(compute_graph);
        // output_result(result);
    }
}
