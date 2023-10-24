#include<iostream>

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

   void insert_end(int n){
		
		if(head==NULL)
		{
	
		 head=new Node();
		 head->data=n;
		 head->next=NULL;	
			
		}
		
		else
		
		{
			
		  Node *p,*ptr;
		  ptr=head;
		  while(ptr->next!=NULL)
		  {
		  	ptr=ptr->next;
		  }
		   
		  p=new Node();
		  p->data=n;
		  p->next= NULL;
		  ptr->next=p;
		   	
		}		
	}
	
		void insert_beg(int n){
		
		if(head==NULL)
		{
	
		 head=new Node();
		 head->data=n;
		 head->next=NULL;	
			
		}
		
		else
		
		{
			
		  Node *p;
		  p=new Node();
		  p->data=n;
		  p->next= head;
		  head=p;
		   	
		}		
	}
	
	void insert_at_value(int pos,int n){
		
		if(head==NULL)
		{
	
		 head=new Node();
		 head->data=n;
		 head->next=NULL;	
			
		}
		
		else
		
		{
		  Node *ptr;
		  ptr=head;
		  while(ptr->data!=pos)
		  { 
		  ptr=ptr->next;
		
		  	}
		  Node *p;
		  p=new Node();
		  p->data=n;
		  p->next= ptr->next;
		  ptr->next=p;
		  }
		    	
		}
		
	void display()
	{
	Node *ptr;
	ptr=head;
	if(ptr==NULL)
	{
		cout << " \nNo data is in the list.."<<endl;
		return;
	}
	else{
		
		while(ptr!=NULL){
			cout<<ptr->data<<endl;
			ptr=ptr->next;
		}
	}
	
    }	
	
	
	
    void delete_beg() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void delete_end() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* ptr = head;
        while (ptr->next->next != NULL) {
            ptr = ptr->next;
        }

        delete ptr->next;
        ptr->next = NULL;
    }

    void delete_at_value(int val) {
        if (head == NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* ptr = head;
        while (ptr->next != NULL && ptr->next->data != val) {
            ptr = ptr->next;
        }

        if (ptr->next != NULL) {
            Node* temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
        } else {
            cout << "Value not found in the list." << endl;
        }
    }

    // ... (display method remains the same)
};

int main() {
    Node n;
    n.insert_beg(1);
    n.insert_beg(2);
    n.insert_end(1);
    n.insert_end(2);
    n.insert_end(20);
    n.insert_at_value(2, 50);
    n.insert_end(30);
    n.insert_beg(5);

    n.display();
	cout<<"Hi New list nicha ha"<<endl;
    n.delete_beg();
    n.delete_end();
    n.delete_at_value(20);

    n.display();
    
    return 0;
}
