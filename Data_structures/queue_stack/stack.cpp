#include <iostream>
#include <sstream>
#include <string>
using namespace std;
struct node{
	int info;
	node *next;
};
node *head,*cur;
class Stack{
public:
	void push(int c){
			if(head==NULL){
				head=new node;
				cur=head;
				cur->info=c;
			}
			else{
				cur->next=new node;
				cur=cur->next;
				cur->info=c;
			}

	}
	void pop(){
		if(cur==head){
			head=NULL;
			delete cur;
		}
		else{
			node *temp;
			temp=head;
			while(temp->next!=cur){
				temp=temp->next;
			}
			cur=temp;
			temp=temp->next;
			cur->next=NULL;
			delete temp;
		}
	}
	void print(){
		if(head==NULL){
			cout<<"nothing to print..\n";
			return;
		}
		node *temp;
		temp=head;
		while(temp->next!=NULL){
			cout<<temp->info<<"  ";
			temp=temp->next;
		}
		cout<<temp->info<<"\n";
	}
};
int main(){
		Stack S;
	int a;
	
	int b=1;
	while(b==1){
		cout<<"1.push....\n2.pop....\n3.print...\n4.exit...\n";
		cin>>a;
		switch(a){
			case 1:
				cout<<"enter the element to insert...";
		        int c;
		        cin>>c;
				S.push(c);
				break;
			case 2:
				S.pop();
				break;
			case 3:
				S.print();
				break;
			case 4:
				b=0;
				break;
			default:
				cout<<"entr proper input..\n";
		}
	}
}
