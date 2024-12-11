#include <iostream>
#include <string>
#include <tuple>
#include "node.hpp"
#include "parser.hpp"
using namespace std;


/*
The parser splits each value from the lowest-priority operation farthest to the left
Eache node has 4 things: the base equation(value), a left and right (which each have part of the equation), 
    and an operation that is supposed to be done between the two halves

These will split until there are not more operators(there is inly a number remining in the node value), creating a binary tree

The idea is that the calculator will start from the bottome left and move up, calculating each node until the root is finally calculated


Ex:              (x+4)-4*7
              |             |
            (x+4)    -     4*7
          |       |     |       |
          x   +   4     4   *   7

*/
string Parser::split_input(Node* root)
{
    // Initializes nodes for current split
    Node* l = new Node;
    Node* r = new Node;
    string expression = root->value;
    int operate_split = -1;
    // Tracks the highest level of priority found (expression is seperated by the lowest priority operator) 1==exponent, 2==mult/division, 3==addition/subtraction
    int priority = 0;

    int index = 0;
    while (index < expression.length())
    {
        if (expression[index] == '(')
        {
            int closing_index = -1;
            int search_index = index;
            while (search_index < expression.length())
            {
                // Find farthest ')' character, which should pair with the '(' character
                if (expression[search_index] == ')')
                {
                    closing_index = search_index;
                }
                // Finds a closing after the furthest bracket, ends search
                else if ((expression[search_index] == '(') && (search_index > closing_index) && (closing_index != -1))
                {
                    // Track # of closing brackets and opening ones, only skips when the two match
                    int closing_num = 0;
                    int opening_num = 0;
                    int temp_search = search_index;
                    while (temp_search < expression.length())
                    {
                        if (expression[temp_search] == '(')
                        {
                            opening_num++;
                        }
                        else if (expression[temp_search] == ')')
                        {
                            closing_num++;
                        }
                        temp_search++;
                    }
                    // Skip the rest of the search
                    if (closing_num == opening_num)
                    {
                        search_index = expression.length();
                    }
                }
                search_index++;
            }
            // If a closing bracket was not found, raises error
            if (closing_index == -1)
            {
                return "A closing bracket is missing from the equation";
            }
            // Removes excess brackets, continues search at the new beginning of the expression
            else if ((closing_index == expression.length() - 1) && (index == 0))
            {
                expression = expression.substr(1,expression.length() - 2);
                index = -1;
            }
            // Moves index past terms in set of paranthesis
            else
            {
                index = closing_index;
            }
                    
        }
        else if((expression[index] == '*') && (expression[index+1] == '*') && (priority <= 1))
        {
            priority = 1;
            operate_split = index;
            // Moves an extra index since exponentiation is 2 characters
            index++;
        }
        else if ((expression[index] == '*' || expression[index] == '/') && (priority <= 2))
        {   
            // Handle divide by zero 
            if (index < expression.size() - 1 && expression[index] == '/' && expression[index + 1] == '0') {
                return "Divide by zero.";
            }

            priority = 2;
            operate_split = index;
        }
        else if((expression[index] == '+' || expression[index] == '-') && (priority <= 3))
        {
            priority = 3;
            operate_split = index;
        }
        // Catches extra closing brackets, gives error
        else if (expression[index] == ')')
        {
            return "An opening bracket is missing from the equation";
        }
        index++;

    }
    // Adds left + right nodes if the expression is to be split
    if (operate_split != -1)
    {
        if (expression[operate_split+1] != '*')
        {
            root->operate = expression[operate_split];
            l->value = expression.substr(0, operate_split);
            root->left = l;
            r->value = expression.substr(operate_split + 1, expression.length() - (operate_split + 1));
            root->right = r;
        }
        else
        {
            l->value = expression.substr(0, operate_split);
            root->left = l;
            r->value = expression.substr(operate_split + 2, expression.length() - (operate_split + 1));
            root->right = r;
            root->operate = "**";
        }
    }
    // Return an empty strin to indicate the function ran successfully
    return "";
            
}

// Recursively splits the root into two nodes, then moves to both of the nodes until they can no longer be split
string Parser::create_tree_recursive(Node* root)
{
    // Uncomment for testing: 
    // cout << root->value << "\n";
    string error_message = split_input(root);

    if (error_message != "") {
        return error_message;
    }

    if (root->left != NULL)
    {
        create_tree_recursive(root->left);
    }
    if (root->right != NULL)
    {
        create_tree_recursive(root->right);
    }
}
// Starts the recursive loop at the root(expression given)
tuple<Node*, string> Parser::create_tree(string expression)
{
    Node* root = new Node;
    root->value = expression;
    string error_message = create_tree_recursive(root);

    return make_tuple(root, error_message);
}