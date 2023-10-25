#include <iostream>
using namespace std;

const int SIZE = 100; 

class Stack{
private:
    int top;
    int arr[SIZE];

public:
    Stack() {
        top = -1; 
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == SIZE - 1;
    }
    void push(int data) {
        if (isFull()) {
            cout << "Stack is full!!!!!" << endl;
            return;
        }
        arr[++top] = data;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!!!!!" << endl;
            return;
        }
        --top;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!!!!!" << endl;
            return -1; 
        }
        return arr[top];
    }
};

int main() {
    Stack stack;

    cout << "Select an Operation:" << endl;
    cout << "1. to Push" << endl;
    cout << "2. to Pop" << endl;
    cout << "3. to Peek" << endl;
    cout << "4. Is stack Full" << endl;
    cout << "5. Is stack Empty" << endl;
    cout << "6. Quit" << endl;

    int c, d;

    do {
        cout << "Choose an Option : ";
        cin >> c;

        switch (c) {
            case 1:
                cout << "Enter data: ";
                cin >> d;
                stack.push(d);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Top element of stack is " << stack.peek() << endl;
                break;
            case 4:
                if (stack.isFull()) {
                    cout << "Stack is full." << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;
            case 5:
                if (stack.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 6:
                cout << "Exiting program......" << endl;
                break;
            default:
                cout << "Select a valid operation" << endl;
        }
    } while (c != 6);

    return 0;
}

