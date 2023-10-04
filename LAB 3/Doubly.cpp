#include<iostream>
using namespace std;
class Node{
	private:	
	int data;
	Node *next;
	Node *prv;
		
	public:
	Node *head;
	
	Node(){
		head=NULL;
	}
	
	void insert_beg(int n){
		
		if(head==NULL){
	
		 head=new Node();
		 head->data=n;
		 head->next=NULL;
		 head->prv=NULL;	
			
		}
		
		else{
			
		  Node *p;
		  p=new Node();
		  p->data=n;
		  p->next= head;
		  p->prv= NULL;
		  head=p;
		   	
		}		
	}
	
		void insert_at_posi(int pos, int n){
		
		if(head==NULL)
		{
	
		 head=new Node();
		 head->data=n;
		 head->next=NULL;
		 head->prv=NULL;	
			
		}
		
		else
		
		{
		  Node *temp;
		  Node *p;
		  p=new Node();
		  p->data=n;
		  temp=head;
		  for(int i=2; i<pos; i++)
		  { 
		  temp = temp->next;
		
		  	}
		  p->next= temp->next;
		  temp->next = p;
		  p->prv = temp;
		  
		  }
		    	
		}
		void insert_at_val(int val, int n){
		
		if(head==NULL)
		{
	
		 head=new Node();
		 head->data=n;
		 head->next=NULL;
		 head->prv=NULL;	
			
		}
		
		else
		
		{
		  Node *temp;
		  Node *p;
		  p=new Node();
		  p->data=n;
		  temp=head;
		  while(temp->data!= val)
		  { 
		  temp = temp->next;
		
		  	}
		  p->next= temp->next;
		  temp->next = p;
		  p->prv = temp;
		  
		  }
		    	
		}
		void insert_end(int n){
		
		if(head==NULL){
	
		 head=new Node();
		 head->data =n;
		 head->next=NULL;
		 head->prv=NULL;	
			
		}
		
		else{
			
		  Node *p;
		  p=new Node();
		  p->data=n;
		  p->next = NULL;
		  Node *temp;
		  temp = head;
		  while(temp->next!=NULL){
		  	temp = temp->next;
		  }
		  p->prv = temp;
		  temp->next = p;
		}		
	}
	
	
	void del_beg(){
		
		if(head==NULL){
	
		 cout<<"No Nodes Exist"<<endl;	
			
		}
		
		else{
			
		  Node *ptr;
		  ptr = head;
		  head = head->next;
		  head->prv = ptr;
		  delete(ptr);
		  ptr = NULL;
		}		
	}
	
	void del_end(){
		
		if(head==NULL){
	
		 cout<<"No Nodes Exist"<<endl;	
			
		}
		
		else{
			
		  Node *temp;
		  Node *temp1;
		  temp = head;
		  while(temp->next->next!=NULL){
		  	temp1 = temp;
		  	temp = temp->next;
		  }
		  temp->next = NULL;
		  temp->prv = temp1;
		  delete(temp);
		}		
	}
	
	void del_at_posi(int pos){
		
		if(head==NULL)
		{
	
		 cout<<"No Node Exist"<<endl;	
			
		}
		
		else
		
		{
		  Node *temp;
		  Node *temp1;
		  temp=head;
		  for(int i=1; i<pos; i++)
		  { 
		  temp1 = temp;
		  temp = temp->next;
		
		  	}
		  temp1->next = temp->next;
		  temp->prv = temp1;
		  delete(temp);
		  temp = NULL;
		  
		  }
		    	
		}
		
		
		void del_at_value(int n){
		
		if(head==NULL)
		{
	
		 cout<<"No Node Exist"<<endl;	
			
		}
		
		else
		
		{
		  Node *temp;
		  Node *temp1;
		  temp=head;
		  while(temp->data!= n)
		  { 
		  temp1 = temp;
		  temp = temp->next;
		
		  	}
		  temp1->next = temp->next;
		  temp->prv = temp1;
		  delete(temp);
		  temp = NULL;		  
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
	
};

int main()
{
	Node n;
    
    n.insert_beg(20);
    n.insert_beg(30);
    n.insert_beg(40);
    n.insert_beg(50);
    n.insert_beg(60);
    n.insert_beg(70);
    n.display();

//    n.del_beg();
//    n.display();

//    n.del_at_posi(4);
//    n.display();
//    n.del_at_value(40);

//    n.display();

//    n.del_end();
//    n.display();

	n.insert_at_posi(3, 111);
	n.display();

	n.insert_at_val(30, 111);
	n.display();

	n.insert_end(1122);
	n.display();
	return 0;
	
}
