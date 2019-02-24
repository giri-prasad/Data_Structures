#include <iostream>
#include <sstream>
#include <string>
using namespace std;
struct node{
	int info;
	node *next;
};
node *head,*cur;
class Queu{
public:
	void insert(int c){
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
	void del(){
		if(cur==head){
			head=NULL;
			delete cur;
		}
		else{
			node *temp;
			temp=head;
			head=head->next;
			temp->next=NULL;
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
		Queu S;
	int a;
	
	int b=1;
	while(b==1){
		cout<<"1.insert....\n2.delete....\n3.print...\n4.exit...\n";
		cin>>a;
		switch(a){
			case 1:
				cout<<"enter the element to insert...";
		        int c;
		        cin>>c;
				S.insert(c);
				break;
			case 2:
				S.del();
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
