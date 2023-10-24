#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            head->next = head; // Make it circular by pointing to itself
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Make it circular
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        }
        else {
            Node* temp = head;
            do {
                cout << temp->data << " -> ";
                temp = temp->next;
            } while (temp != head);
            cout<< endl;
        }
    }

    void reverse() {
        if (head != NULL) {
            Node* prev = NULL;
            Node* current = head;
            Node* next = NULL;

            do {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            } while (current != head);

            head->next = prev; // Update the head to point to the new first node
            head = prev;
        }
    }
};

int main() {
    CircularLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    cout << "Original list: ";
    list.display();

    list.reverse();

    cout << "Reversed list: ";
    list.display();

    return 0;
}

