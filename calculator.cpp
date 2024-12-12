#include "calculator.hpp"
#include <stdexcept>
#include <cmath>


float Calculator::calculate(Node* root) {
    if (!root) {
        throw std::invalid_argument("Null node encountered in calculation.");
    }

    //Leaf node (will be a number)
    if (!root->left && !root->right) {
        return std::stof(root->value);
    }

    //Recursive calculation for left and right subtrees
    float leftValue = calculate(root->left);
    float rightValue = calculate(root->right);

    //Perform the operation at the current node
    if (root->operate == "+") {
        return leftValue + rightValue;
    } else if (root->operate == "-") {
        return leftValue - rightValue;
    } else if (root->operate == "*") {
        return leftValue * rightValue;
    } else if (root->operate == "/") {
        if (rightValue == 0) {
            throw std::runtime_error("Division by zero.");
        }
        return leftValue / rightValue;
    } else if (root->operate == "%") {
        if (rightValue == 0) {
            throw std::runtime_error("Division by zero.");
        }
        int l = leftValue;
        int r = rightValue;
        return l % r;
    } else if (root->operate == "**") {
        return std::pow(leftValue, rightValue);
    } else {
        throw std::invalid_argument("Unknown operation: " + root->operate);
    }
}
