#include <iostream>

using namespace std;

class Deque {
private:
    int front, rear, capacity;
    int* arr;

public:
    Deque(int size) {
        capacity = size;
        front = rear = -1;
        arr = new int[size];
    }

    // Function to check if the deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the deque is full
    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }

    // Function to add an element to the front of the deque
    void pushFront(int item) {
        if (isFull()) {
            cout << "Deque is full. Cannot push to the front." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }

        arr[front] = item;
        cout << item << " pushed to the front of the deque." << endl;
    }

    // Function to add an element to the rear of the deque
    void pushBack(int item) {
        if (isFull()) {
            cout << "Deque is full. Cannot push to the rear." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = item;
        cout << item << " pushed to the rear of the deque." << endl;
    }

    // Function to remove an element from the front of the deque
    void popFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot pop from the front." << endl;
            return;
        }

        int frontElement = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }

        cout << frontElement << " popped from the front of the deque." << endl;
    }

    // Function to remove an element from the rear of the deque
    void popBack() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot pop from the rear." << endl;
            return;
        }

        int rearElement = arr[rear];
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear--;
        }

        cout << rearElement << " popped from the rear of the deque." << endl;
    }

    // Function to peek at the front element of the deque
    int peekFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot peek at the front." << endl;
            return -1;
        }
        return arr[front];
    }

    // Function to peek at the rear element of the deque
    int peekRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot peek at the rear." << endl;
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Deque deque(5);

    cout << "Is the deque empty? " << (deque.isEmpty() ? "Yes" : "No") << endl;

    deque.pushFront(5);
    deque.pushFront(20);
    deque.pushBack(40);
    deque.pushBack(3);

    cout << "Front element of the deque: " << deque.peekFront() << endl;
    cout << "Rear element of the deque: " << deque.peekRear() << endl;

    deque.popFront();
    deque.popBack();

    cout << "Front element of the deque after popFront: " << deque.peekFront() << endl;
    cout << "Rear element of the deque after popBack: " << deque.peekRear() << endl;

    return 0;
}

