#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
	cout<<endl;
    }

    void reverse() {
        Node* temp = NULL;
        Node* current = head;

        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != NULL) {
            head = temp->prev;
        }
    }
};

int main() {
    DoublyLinkedList list;
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

