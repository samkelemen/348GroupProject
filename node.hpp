#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

class Node
{
    public:
        Node* left;
        Node* right;
        string value;
        string operate;
};

#endif