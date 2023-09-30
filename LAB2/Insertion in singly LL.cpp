#include<iostream>
using namespace std;
class Node{
	private:
	 int data;
	 Node *next;	
	public:
	 Node *head;
	 Node(){
	 	head==NULL;
	 }

//inserion at the Begining*************************************************
	 void insert_at_begin(int n){
	 	if(head==NULL){
	 		head=new Node();
	 		head->data=n;
	 		head->next=NULL;
		 }
		 else {
		 	Node *p;
		 	p=new Node();
		 	p->data=n;
		 	//p->next=NULL;
		 	p->next=head;
		 	head=p;
		 }
		disp();
	 }


//inserion at the END*************************************************

	 void insert_at_end(int n){
	 	if(head==NULL){
	 		head=new Node();
	 		head->data=n;
	 		head->next=NULL;
		 }
		 else{
		 	Node *p, *temp;
		 	temp=head;
		 	while (temp->next!=NULL){
		 		temp=temp->next;
			 }
			p=new Node();
			p->next=NULL;
			p->data=n;
			temp->next=p;	
		 }
		disp();
	 	
	 }
//inserion at after Specific Location*************************************************
	void insert_at_afterval(int loc,int n){

		if(head==NULL)
		{
	
		 head=new Node();
		 head->data=n;
		 head->next=NULL;	
			
		}
		
		else
		
		{
		  Node *temp;
		  temp=head;
		  while(temp->data!=loc)
		  { 
		  temp=temp->next;
		
		  }
		  Node *p;
		  p=new Node();
		  p->data=n;
		  p->next= temp->next;
		  temp->next=p;
		  }
		  cout << "\nInserted Successfully After location: "<<loc;
		  disp();
		    	
		}
//inserion before the Specific Location*************************************************		
		void insert_at_beforval(int loc,int n){
		
		if(head==NULL)
		{
	
		 head=new Node();
		 head->data=n;
		 head->next=NULL;	
			
		}
		
		else
		
		{
		  Node *temp, *temp2;
		  
		  temp=head;
		  temp2=head;
		  while(temp->data!=loc)
		  { 
		  temp2 = temp;
		  temp = temp->next;
		  }
		  
		  Node *p;
		  p=new Node();
		  p->data=n;
		  if(temp==head){
		  	p->next=head;
		  	head=p;
		  }
		  else{
		  	temp2->next=p;
		  p->next=temp;
		  }
		  
		  }
		  cout << "\nInserted Successfully before location";
		  disp();
		    	
		}


	

//Display*************************************************	 
	void disp()
	{
	Node *temp;
	temp=head;
	if(temp==NULL)
	{
		cout << " \nNo data is in the list.."<<endl;
		return;
	}
	else{
		cout << " \nThe items present in the list are :";
		while(temp!=NULL){
			cout << " " << temp->data;
			temp = temp->next;
		}
		cout <<endl;
	}
    }
    
    
};
int main(){
	Node obj;
	int n,v;
do{

	cout<<"Select any One Operation You want to Perform.."<<endl;
	cout<<"1: To add Node at Begining"<<endl;
	cout<<"2: To add Node at End"<<endl;
	cout<<"3: To add Node at Specific Location"<<endl;
	cout<<"4: to exit"<<endl;
	cin>>n;
	switch (n){
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
			cout<<"Enter location value: ";
			cin>>loc;
			cout << "Enter the value to insert: ";
			cin >> v;
			cout<<"\nSelect any One...."<<endl;
			cout<<"1:After Location"<<endl;
			cout<<"2:Before Location"<<endl;
			cin>>o;
				switch (o){
					case 1:
						
						obj.insert_at_afterval(loc,v);
						break;
					case 2:
						
						obj.insert_at_beforval(loc,v);
						break;
					default:
						cout << "Choose valid Option"<<endl;
						break;
					}
					break;
		case 4:
			exit(1);
		default:
			cout << "Choose valid Option"<<endl;
			break;
	}
	system("pause");
	
} while (n != 4);
	system("pause");
	return 0;
}
