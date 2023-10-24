#include <iostream>

using namespace std;

class LinearQueue {
private:
    int front, rear, capacity;
    int* queue;

public:
    LinearQueue(int size) {
        capacity = size;
        front = rear = -1;
        queue = new int[size];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear == capacity - 1);
    }

    // Function to add an element to the rear of the queue (enqueue)
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear++;
        queue[rear] = item;

        cout << item << " enqueued to the queue." << endl;
    }

    // Function to remove an element from the front of the queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << queue[front] << " dequeued from the queue." << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Function to peek at the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value to indicate an error
        }
        return queue[rear];
    }
     int peekk() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value to indicate an error
        }
        return queue[front];
    }
};

int main() {
    LinearQueue queue(5);

    cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is the queue full? " << (queue.isFull() ? "Yes" : "No") << endl;

    queue.enqueue(5);
    queue.enqueue(20);
    queue.enqueue(40);
    queue.enqueue(3);

    cout << "rear element of the queue: " << queue.peek() << endl;

    queue.dequeue();

    cout << "Front element of the queue after dequeue: " << queue.peekk() << endl;

    return 0;
}

