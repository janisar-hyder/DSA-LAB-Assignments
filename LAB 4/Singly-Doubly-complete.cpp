#include <iostream>
using namespace std;
class Node
{
private:
	int data;
	Node *next;

public:
	Node *head;
	Node()
	{
		head == NULL;
	}
	
	// inserion at the Begining*************************************************
	void insert_at_begin(int n)
	{
		if (head == NULL)
		{
			head = new Node();
			head->data = n;
			head->next = NULL;
		}
		else
		{
			Node *p;
			p = new Node();
			p->data = n;
			// p->next=NULL;
			p->next = head;
			head = p;
		}
		disp();
	}

// inserion at the END*************************************************

	void insert_at_end(int n)
	{
		if (head == NULL)
		{
			head = new Node();
			head->data = n;
			head->next = NULL;
		}
		else
		{
			Node *p, *temp;
			temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			p = new Node();
			p->next = NULL;
			p->data = n;
			temp->next = p;
		}
		disp();
	}
// inserion at after Specific Location*************************************************
	void insert_at_afterval(int loc, int n)
	{

		if (head == NULL)
		{

			head = new Node();
			head->data = n;
			head->next = NULL;
		}

		else

		{
			Node *temp;
			temp = head;
			while (temp->data != loc)
			{
				temp = temp->next;
			}
			Node *p;
			p = new Node();
			p->data = n;
			p->next = temp->next;
			temp->next = p;
		}
		cout << "\nInserted Successfully After location: " << loc;
		disp();
	}
// inserion before the Specific Location*************************************************
	void insert_at_beforval(int loc, int n)
	{

		if (head == NULL)
		{

			head = new Node();
			head->data = n;
			head->next = NULL;
		}

		else

		{
			Node *temp, *temp2;

			temp = head;
			temp2 = head;
			while (temp->data != loc)
			{
				temp2 = temp;
				temp = temp->next;
			}

			Node *p;
			p = new Node();
			p->data = n;
			if (temp == head)
			{
				p->next = head;
				head = p;
			}
			else
			{
				temp2->next = p;
				p->next = temp;
			}
		}
		cout << "\nInserted Successfully before location";
		disp();
	}

//**************************deletion****************************************************************
//deletion at begining
	void delete_at_begin()
	{
		if (head == NULL)
		{
			cout << "Linked list not Exist";
		}
		else
		{

			Node *temp;
			temp = head;
			head = temp->next;
			delete temp;
			temp = NULL;
		}
		disp();
	}
	
//****************************************************************	
//deletion at END
void delete_at_end(){
		
		if(head==NULL){
		 cout<<"No Nodes Exist"<<endl;		
		}
		else{	
		  Node *ptr;
		  Node *ptr1;
		  ptr = head;
		  while(ptr->next!=NULL){
		  	ptr1 = ptr;
		  	ptr = ptr->next;
		  }
		  ptr1->next = NULL;
		  delete(ptr);
		}
		disp();		
	}	
	
	
//****************************************************************	
//deletion at specific value
void delete_at_value(int x){
		
	Node *temp, *temp1;
	temp = head;
	if (temp->data == x)
	{
		head = temp->next;
		delete temp;
		return;
	}
	temp1 = temp;
	while (temp != NULL)
	{
		if (temp->data == x)
		{
			temp1->next = temp->next;
			delete temp;
			return;
		}
		temp1 = temp;
		temp = temp->next;
	}  	
}


	// Display*************************************************
	void disp()
	{
		Node *temp;
		temp = head;
		if (temp == NULL)
		{
			cout << " \nNo data is in the list..\n\n\n" << endl;
			return;
		}
		else
		{
			cout << " \nThe items present in the list are :";
			while (temp != NULL)
			{
				cout << " " << temp->data;
				temp = temp->next;
			}
			cout <<"\n\n\n"<<endl;
		}
	}
};

//*****--------------DOUBLY------------*****
class Node2
{
private:	
	int data;
	Node2 *next;
	Node2 *prv;
		
	public:
	Node2 *head;
	
	Node2(){
		head=NULL;
	}



//INsertion*******************************	
	void insert_beg(int n){
		if(head==NULL){
		 head=new Node2();
		 head->data=n;
		 head->next=NULL;
		 head->prv=NULL;		
		}
		else{	
		  Node2 *p;
		  p=new Node2();
		  p->data=n;
		  p->next= head;
		  p->prv= NULL;
		  head=p;	
		}
		disp();		
	}
	
	void insert_end(int n){
		if(head==NULL){
		 head=new Node2();
		 head->data =n;
		 head->next=NULL;
		 head->prv=NULL;		
		}	
		else{	
		  Node2 *p;
		  p=new Node2();
		  p->data=n;
		  p->next = NULL;
		  Node2 *temp;
		  temp = head;
		  while(temp->next!=NULL){
		  	temp = temp->next;
		  }
		  p->prv = temp;
		  temp->next = p;
		}
		disp();		
	}
	

void insert_at_val(int val, int n){		
		if(head==NULL)
		{
		 head=new Node2();
		 head->data=n;
		 head->next=NULL;
		 head->prv=NULL;	
		}
		else
		{
		  Node2 *temp;
		  Node2 *p;
		  p=new Node2();
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
		  disp();  	
		}

//DEletion*******************************

void del_beg(){
		if(head==NULL){
		 cout<<"No Nodes Exist"<<endl;		
		}
		else{	
		  Node2 *ptr;
		  ptr = head;
		  head = head->next;
		  head->prv = ptr;
		  delete(ptr);
		  ptr = NULL;
		}
		disp();		
	}
	
void del_end(){
		if(head==NULL){
		 cout<<"No Nodes Exist"<<endl;		
		}
		else{	
		  Node2 *temp;
		  Node2 *temp1;
		  temp = head;
		  while(temp->next->next!=NULL){
		  	temp1 = temp;
		  	temp = temp->next;
		  }
		  temp->next = NULL;
		  temp->prv = temp1;
		  delete(temp);
		}	
		disp();	
	}
	
void del_at_value(int n){		
		if(head==NULL)
		{
		 cout<<"No Node Exist"<<endl;		
		}
		else
		{
		  Node2 *temp;
		  Node2 *temp1;
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
		  disp();  	
		}
	
	
	// Display*************************************************
	void disp()
	{
		Node2 *temp;
		temp = head;
		if (temp == NULL)
		{
			cout << " \nNo data is in the list..\n\n\n" << endl;
			return;
		}
		else
		{
			cout << " \nThe items present in the list are :";
			while (temp != NULL)
			{
				cout << " " << temp->data;
				temp = temp->next;
			}
			cout <<"\n\n\n"<<endl;
		}
	}
};




int main()
{
	
	Node obj;
	Node2 obj2;
	int n, v, id, mn;
	do
	{
	cout << "Select any One Linked List" << endl;
	cout << "1: SINGLY" << endl;
	cout << "2: DOUBLY" << endl;
	cin >> mn;
	switch (mn){
	case 1:
		min:
		cout << "Select any One Operation You want to Perform.." << endl;
		cout << "1: INSERTION" << endl;
		cout << "2: DELETION" << endl;
		cin >> id;
		switch (id)
		{

		case 1:
			cout << "1: To add Node at Begining" << endl;
			cout << "2: To add Node at End" << endl;
			cout << "3: To add Node at Specific Location" << endl;
			cout << "4: to Back" << endl;
			cout << "5: to exit" << endl;
			cin >> n;
			switch (n)
			{
			case 1:
				cout << "\nEnter the value to insert: ";
				cin >> v;
				obj.insert_at_begin(v);
				break;
			case 2:
				cout << "\nEnter the value to insert: ";
				cin >> v;
				obj.insert_at_end(v);
				break;
			case 3:
				int o, loc;
				cout << "Enter location value: ";
				cin >> loc;
				cout << "Enter the value to insert: ";
				cin >> v;
				cout << "\nSelect any One...." << endl;
				cout << "1:After Location" << endl;
				cout << "2:Before Location" << endl;
				cin >> o;
				switch (o)
				{
				case 1:

					obj.insert_at_afterval(loc, v);
					break;
				case 2:

					obj.insert_at_beforval(loc, v);
					break;
				default:
					cout << "Choose valid Option" << endl;
					break;
				}
				break;
			case 4:
				goto min;
			case 5:
				exit(1);
			default:
				cout << "Choose valid Option" << endl;
				break;
			}
			break;
			system("pause");

		case 2:

			cout << "1: To Delete Node from Begining" << endl;
			cout << "2: To Delete Node from End" << endl;
			cout << "3: To Delete Specific Node" << endl;
			cout << "4: to Back" << endl;
			cout << "5: to exit" << endl;
			cin >> n;
			switch (n)
			{
			case 1:
				cout<<"Node deleted from Begining....";
				obj.delete_at_begin();
				break;
			case 2:
				cout<<"Node deleted from END....";
				obj.delete_at_end();
				break;
			}
			case 3:
			cout << "Enter the node value to Delete: ";
				cin >> v;
				obj.delete_at_value(v);
				obj.disp();
				break;
			default:
				cout << "Choose valid Option" << endl;
				break;
			
		}
		break;
//end of case singly
//-----------------------------------------------
	case 2:
		tg:
		cout << "Select any One Operation You want to Perform.." << endl;
		cout << "1: INSERTION" << endl;
		cout << "2: DELETION" << endl;
		cin >> id;
		switch (id){
//insertion in doubly		
		case 1:
			
			cout << "1: To add Node at Begining" << endl;
			cout << "2: To add Node at End" << endl;
			cout << "3: To add Node at Specific Location" << endl;
			cout << "4: to Back" << endl;
			cout << "5: to exit" << endl;
			cin >> n;
			switch (n)
			{
			case 1:
				cout << "\nEnter the value to insert: ";
				cin >> v;
				obj2.insert_beg(v);
				break;
				
			case 2:
				cout << "\nEnter the value to insert: ";
				cin >> v;
				obj2.insert_end(v);
				break;	
			
			case 3:
				int o, loc;
				cout << "Enter location value: ";
				cin >> loc;
				cout << "Enter the value to insert: ";
				cin >> v;
				obj2.insert_at_val(loc, v);
			case 4:
				goto tg;
			case 5:
				exit(1);
			default:
				cout << "Choose valid Option" << endl;
				break;
			}
			break;
//deletion in doubly
		case 2:
			cout << "1: To Delete Node from Begining" << endl;
			cout << "2: To Delete Node from End" << endl;
			cout << "3: To Delete Specific Node" << endl;
			cout << "4: to Back" << endl;
			cout << "5: to exit" << endl;
			cin >> n;
			switch (n)
			{
			case 1:
				cout<<"Node deleted from Begining....";
				obj2.del_beg();
				break;
			case 2:
				cout<<"Node deleted from END....";
				obj2.del_end();
				break;
			case 3:
			cout << "Enter the node value to Delete: ";
				cin >> v;
				obj2.del_at_value(v);
				break;
			default:
				cout << "Choose valid Option" << endl;
				break;
			}
				

		}
		break;
//end of case doubly
//-----------------------------------
	default:
		cout << "Choose valid Option" << endl;
		break;
		

//end of singly/doubly switch
	}
	

	} while (n != 4);
	system("pause");
	return 0;
}
