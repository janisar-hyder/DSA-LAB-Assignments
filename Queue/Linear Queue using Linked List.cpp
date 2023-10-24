#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class LinearQueue {
private:
    Node* front;
    Node* rear;

public:
    LinearQueue() : front(NULL), rear(NULL) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Function to add an element to the rear of the queue (enqueue)
    void enqueue(int item) {
        Node* newNode = new Node(item);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << item << " enqueued to the queue." << endl;
    }

    // Function to remove an element from the front of the queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        int frontElement = front->data;
        Node* temp = front;

        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
        }

        delete temp;
        cout << frontElement << " dequeued from the queue." << endl;
    }

    // Function to peek at the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value to indicate an error
        }
        return front->data;
    }
};

int main() {
    LinearQueue queue;

    cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    queue.enqueue(5);
    queue.enqueue(20);
    queue.enqueue(40);
    queue.enqueue(3);

    cout << "Front element of the queue: " << queue.peek() << endl;

    queue.dequeue();

    cout << "Front element of the queue after dequeue: " << queue.peek() << endl;

    return 0;
}

