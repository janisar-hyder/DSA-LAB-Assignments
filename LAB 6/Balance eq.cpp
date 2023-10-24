#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string equation) {
    stack<char> symbolStack;

     for (int i = 0; i < equation.length(); i++){
        char c = equation[i];
        if (c == '(' || c == '[' || c == '{') {
            symbolStack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (symbolStack.empty()) {
                return false; 
            }

            char top = symbolStack.top();
            symbolStack.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false; 
            }
        }
    }

    return symbolStack.empty(); 
}

int main() {
    string equation;
    cout << "Enter an equation: ";
    cin >> equation;

    if (isBalanced(equation)) {
        std::cout << "The equation is balanced." << std::endl;
    } else {
        cout << "The equation is not balanced." << std::endl;
    }

    return 0;
}

