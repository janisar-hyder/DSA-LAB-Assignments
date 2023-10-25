#include <iostream>
using namespace std;
class Node {
private:
    int data;
    Node* next;

public:
    Node* head;

    Node() {
        head = NULL;
    }

    void SLL(int n) {

        if (head == NULL) {

            head = new Node();
            head->data = n;
            head->next = NULL;

        }

        else {

            Node* p;
            p = new Node();
            p->data = n;
            p->next = head;
            head = p;

        }
    }

    void display() {
        Node* ptr;
        ptr = head;
        if (ptr == NULL) {
            cout << " \nNo data is in the list.." << endl;
            return;
        }
        else {

            while (ptr != NULL) {
                cout << ptr->data << endl;
                ptr = ptr->next;
            }
        }

    }

    bool isPalindrome() {
        if (head == NULL) {
            cout << "The list is empty, so it's considered a palindrome." << endl;
            return true;
        }

        Node* fast = head;
        Node* slow = head;
        Node* prev_slow = head;
        Node* mid = NULL;
        bool isPalindrome = true;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev_slow = slow;
            slow = slow->next;
        }

        if (fast != NULL) {
            mid = slow;
            slow = slow->next;
        }

        Node* second_half = slow;
        prev_slow->next = NULL;
        reverseList(head);

        isPalindrome = compareLists(head, second_half);

        reverseList(second_half);

        if (mid != NULL) {
            prev_slow->next = mid;
            mid->next = second_half;
        } else {
            prev_slow->next = second_half;
        }

        return isPalindrome;
    }

    void reverseList(Node*& head) {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    bool compareLists(Node* head1, Node* head2) {
        Node* temp1 = head1;
        Node* temp2 = head2;

        while (temp1 && temp2) {
            if (temp1->data == temp2->data) {
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else {
                return false;
            }
        }

        if (!temp1 && !temp2) {
            return true;
        }
        return false;
    }
};

int main() {
    Node n;
    n.SLL(1);
    n.SLL(2);
    n.SLL(2);
    n.SLL(1);
    n.display();

    if (n.isPalindrome()) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}

