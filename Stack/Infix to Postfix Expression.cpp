#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> operatorStack; //declaring stack
    string postfix;

    for (char c : infix) {   //taking one value from string here
        if (isalnum(c)) {
            // If the character is an operand, add it to the postfix string
            postfix += c;
        } else if (c == '(') {
            // If the character is an open parenthesis, push it onto the stack
            operatorStack.push(c);
        } else if (c == ')') {
            // If the character is a close parenthesis, pop operators from the stack
            // and append them to the postfix string until an open parenthesis is encountered
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop the open parenthesis
        } else if (isOperator(c)) {
            // If the character is an operator, pop operators from the stack and append
            // them to the postfix string as long as they have higher or equal precedence
            while (!operatorStack.empty() && operatorStack.top() != '(' &&
                   getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            // Push the current operator onto the stack
            operatorStack.push(c);
        }
    }

    // Pop any remaining operators from the stack and append them to the postfix string
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
