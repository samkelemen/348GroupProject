#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <iostream>
#include "node.hpp"
using namespace std;

class Parser
{
    private:
        void split_input(Node* root);

        void create_tree_recursive(Node* root);
    public:
        Node* create_tree(string expression);
};

#endif