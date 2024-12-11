#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <iostream>
#include "node.hpp"
using namespace std;

class Parser
{
    private:
        string split_input(Node* root);

        string create_tree_recursive(Node* root);
        
    public:
        tuple<Node*, string> create_tree(string expression);
};

#endif