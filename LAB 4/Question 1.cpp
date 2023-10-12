#include <iostream>

using namespace std; // Add this line to include the std namespace

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        // Check if the linked list is empty.
        if (head == NULL) {
            cout << "The linked list is empty." << endl;
            return;
        }

        // Create a temporary pointer to traverse the linked list.
        Node* ptr = head;

      
        cout << "The linked list is:" << endl;
        while (ptr != nullptr) {
            cout << ptr->data << "\t";
            ptr = ptr->next;
        }
        cout<<endl;
		cout<<endl;
        
        ptr = head;

     
        cout << "****head address:**** " << &head << endl;
        cout<<"-------------------------------------"<<endl;
        cout << "****head address:**** " << head << endl;
        cout<<"-------------------------------------"<<endl;
		
		cout << "****ptr address:**** " << &ptr << endl;
		        cout<<"-------------------------------------"<<endl;

        cout << "****ptr Content:**** " << ptr << endl;
                

		
  
        while (ptr != nullptr) {          
		cout<<"-------------------------------------"<<endl;  
		    cout << "ptr->data:" << ptr->data << endl;
            cout << "ptr:" << ptr << endl;
            cout << "ptr->next:" << ptr->next << endl;
        
            ptr = ptr->next;
        }
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(20);
	list.insert(30);
    list.display();

    return 0;
}
