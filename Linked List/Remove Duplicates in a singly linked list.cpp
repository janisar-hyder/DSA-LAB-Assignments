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

    while (current) {
        Node* runner = current;

        // Remove all duplicate nodes with the same value as the current node
        while (runner->next) {
            if (runner->next->data == current->data) {
                Node* duplicate = runner->next;
                runner->next = duplicate->next;
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
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);

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

