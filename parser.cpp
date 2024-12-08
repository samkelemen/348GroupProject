#include <iostream>
#include <string>
#include "node.hpp"
#include "parser.hpp"
using namespace std;

void Parser::split_input(Node* root)
{
    //initializes nodes for current split
    Node* l = new Node;
    Node* r = new Node;
    string expression = root->value;
    int operate_split = -1;
    //tracks the highest level of priority found (expression is seperated by the lowest priority operator) 1==exponent, 2==mult/division, 3==addition/subtraction
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
                //find farthest ')' character, which should pair with the '(' character
                if (expression[search_index] == ')')
                {
                    closing_index = search_index;
                }
                //finds a closing after the furthest bracket, ends search
                else if ((expression[search_index] == '(') && (search_index > closing_index) && (closing_index != -1))
                {
                    //track # of closing brackets and opening ones, only skips when the two match
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
                    //skip the rest of the search
                    if (closing_num == opening_num)
                    {
                        search_index = expression.length();
                    }
                }
                search_index++;
            }
            //if a closing bracket was not found, raises error
            if (closing_index == -1)
            {
                cout << "A closing bracket was not found";
            }
            //removes excess brackets, continues search at the new beginning of the expression
            else if ((closing_index == expression.length() - 1) && (index == 0))
            {
                expression = expression.substr(1,expression.length() - 2);
                index = -1;
            }
            //moves index past terms in set of paranthesis
            else
            {
                index = closing_index;
            }
                    
        }
        else if((expression[index] == '^') && (priority <= 1))
        {
            priority = 1;
            operate_split = index;
        }
        else if((expression[index] == '*' || expression[index] == '/') && (priority <= 2))
        {
            priority = 2;
            operate_split = index;
        }
        else if((expression[index] == '+' || expression[index] == '-') && (priority <= 3))
        {
            priority = 3;
            operate_split = index;
        }
        //catches extra closing brackets, gives error
        else if (expression[index] == ')')
        {
            cout << "No opening bracket to match the closing one";
        }
        index++;

    }
    //adds left + right nodes if the expression is to be split
    if (operate_split != -1)
    {
        l->value = expression.substr(0, operate_split);
        root->left = l;
        r->value = expression.substr(operate_split + 1, expression.length() - (operate_split + 1));
        root->right = r;
        root->operate = expression[operate_split];
    }
            
}

//recursively splits the root into two nodes, then moves to both of the nodes until they can no longer be split
void Parser::create_tree_recursive(Node* root)
{
    cout << root->value << "\n";
    split_input(root);

    if (root->left != NULL)
    {
        create_tree_recursive(root->left);
    }
    if (root->right != NULL)
    {
        create_tree_recursive(root->right);
    }
}
//starts the recursive loop at the root(expression given)
Node* Parser::create_tree(string expression)
{
    Node* root = new Node;
    root->value = expression;
    create_tree_recursive(root);

    return root;
}