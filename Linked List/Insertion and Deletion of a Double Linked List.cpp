#include <iostream>

using namespace std;

class Node {
private:
    int data;
    Node* next;
    Node* prev;

public:
    Node* head;

    Node() {
        head = NULL;
    }

    void insert_end(int n) {
        if (head == NULL) {
            head = new Node();
            head->data = n;
            head->next = NULL;
            head->prev = NULL;
        } else {
            Node* p, * ptr;
            ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }

            p = new Node();
            p->data = n;
            p->next = NULL;
            p->prev = ptr;
            ptr->next = p;
        }
    }

    void insert_beg(int n) {
        if (head == NULL) {
            head = new Node();
            head->data = n;
            head->next = NULL;
            head->prev = NULL;
        } else {
            Node* p;
            p = new Node();
            p->data = n;
            p->next = head;
            p->prev = NULL;
            head->prev = p;
            head = p;
        }
    }

    void insert_at_value(int pos, int n) {
        if (head == NULL) {
            head = new Node();
            head->data = n;
            head->next = NULL;
            head->prev = NULL;
        } else {
            Node* ptr;
            ptr = head;
            while (ptr->data != pos) {
                ptr = ptr->next;
            }

            Node* p;
            p = new Node();
            p->data = n;
            p->next = ptr->next;
            p->prev = ptr;
            if (ptr->next != NULL) {
                ptr->next->prev = p;
            }
            ptr->next = p;
        }
    }

    void delete_beg() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
    }

    void delete_end() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        if (ptr->prev != NULL) {
            ptr->prev->next = NULL;
        } else {
            head = NULL;
        }
        delete ptr;
    }

    void delete_at_value(int val) {
        if (head == NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* ptr = head;
        while (ptr != NULL && ptr->data != val) {
            ptr = ptr->next;
        }

        if (ptr == NULL) {
            cout << "Value not found in the list." << endl;
            return;
        }

        if (ptr->prev != NULL) {
            ptr->prev->next = ptr->next;
        } else {
            head = ptr->next;
        }

        if (ptr->next != NULL) {
            ptr->next->prev = ptr->prev;
        }

        delete ptr;
    }

    void display() {
        Node* ptr;
        ptr = head;
        if (ptr == NULL) {
            cout << "\nNo data is in the list.." << endl;
            return;
        } else {
            while (ptr != NULL) {
                cout << ptr->data << endl;
                ptr = ptr->next;
            }
        }
    }
};

int main() {
    Node n;
    n.insert_beg(1);
    n.insert_beg(2);
    n.insert_end(108);
    n.insert_end(200);
    n.insert_end(20);
    n.insert_at_value(2, 50);
    n.insert_end(30);
    n.insert_beg(5);

    n.display();
	cout<<"New List is :"<<endl;
    n.delete_beg();
    n.delete_end();
    n.delete_at_value(20);

    n.display();

    return 0;
}
