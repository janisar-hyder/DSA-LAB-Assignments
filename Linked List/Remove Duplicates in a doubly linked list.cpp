#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

void removeDuplicates(Node* head) {
    if (!head)
        return;

    Node* current = head;

    while (current) {
        Node* runner = current->next;

        while (runner) {
            if (runner->data == current->data) {
                // Duplicate found, remove the node
                if (runner->next)
                    runner->next->prev = runner->prev;
                runner->prev->next = runner->next;
                Node* duplicate = runner;
                runner = runner->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(1);
    Node* fourth = new Node(3);
    Node* fifth = new Node(2);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    std::cout << "Original List: ";
    printList(head);

    removeDuplicates(head);

    std::cout << "List after removing duplicates: ";
    printList(head);

    // Clean up memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

