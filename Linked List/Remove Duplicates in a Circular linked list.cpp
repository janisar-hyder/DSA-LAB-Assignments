#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void removeDuplicates(Node* head) {
    if (!head)
        return;

    Node* current = head;

    do {
        Node* runner = current;

        // Remove all duplicate nodes with the same value as the current node
        while (runner->next != head) {
            if (runner->next->data == current->data) {
                Node* duplicate = runner->next;
                runner->next = duplicate->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    } while (current != head);
}

void printList(Node* head) {
    Node* current = head;

    if (!current) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);

    std::cout << std::endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);

    // Make the list circular
    head->next->next->next->next->next = head;

    std::cout << "Original Circular List: ";
    printList(head);

    removeDuplicates(head);

    std::cout << "Circular List after removing duplicates: ";
    printList(head);

    // Clean up memory
    Node* current = head;
    Node* next;
    do {
        next = current->next;
        delete current;
        current = next;
    } while (current != head);

    return 0;
}

