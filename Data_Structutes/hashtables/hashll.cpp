/*
//hash table using linked list....
//assignment 5submission 
//compiled and runned in mac terminal..
//TA.. shalini jain..

*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
const int size=10;
struct node
{
	int a;
	string value;
	node *next;
};
node arrstrt[size];
class hashll{
public:
	hashll(){											//constructor....
		int i;
		for(i=0;i<size;i++){
			arrstrt[i].a =0;
			arrstrt[i].next=NULL;
		}
	}
	int hash(string key){
		int i,j,k,sum=0;
		i=key.length();
		for(j=0;j<i;j++){
			k=key[j];
			sum=sum+k;
		}
		sum=sum % size;
		return sum;
	}
	node *search(string key){
		int sum;
		sum=hash(key);
		if(arrstrt[sum].a == 0){
			return NULL;
		}
		else{
			node *t;
			t=arrstrt[sum].next;
			while(t != NULL){
				if(t->value == key)
					return t;
				t=t->next;
			}
			return NULL;
		}
	}
	void insert(string key){
		int sum;
		sum=hash(key);
		if(arrstrt[sum].a == 0){
			arrstrt[sum].a=1;
			arrstrt[sum].next=new node;
			arrstrt[sum].next->value=key;
			arrstrt[sum].next->next=NULL;
		}
		else{
			node *t;
			t=new node;
			t->value=key;
			t->next=arrstrt[sum].next;
			arrstrt[sum].next=t;
			t=NULL;
		}
	}
	void del(string key){
		node *t;
		int sum;
		t=search(key);
		if(t == NULL){
			cout<<"\n no element to delete..\n";
			return;
		}
		else{
			sum=hash(key);
			if(arrstrt[sum].next == t){
				if(t->next ==NULL){
					arrstrt[sum].a=0;
					arrstrt[sum].next=NULL;
					delete t;
					return;
				}
				else{
					arrstrt[sum].next=t->next;
					t->next=NULL;
					delete t;
					return;
				}
			}
			else{	
				node *tt;
				tt=arrstrt[sum].next;
				while(tt->next != t){
					tt=tt->next;
				}
				tt->next=t->next;
				t->next=NULL;
				delete t;
				return;
			}
		}
	}
	void print(int z){
		if(z >= size || z < 0){
			cout<<"\nenter proper value of array\n";
			return;
		}
		else{
			if(arrstrt[z].a == 0){
				cout<<"\n there is no linked list at all in this part...\n";
				return;
			}
			else{
				node *t;
				t=arrstrt[z].next;
				while(t != NULL){
					cout<<t->value<<endl;
					t=t->next;
				}
				return;
			}
		}
	}
};
int main(){
	hashll H;
	int i=0,j;
	string key;
	node *temp;
	while(i==0){
		cout<<"\n1.insert..2.search..3.delete..4.print.....5.exit...\nenter your choice....";
		cin>>j;
		switch(j){
			case 1:
				cout<<"\nenter the string to insert..";
				cin>>key;
				H.insert(key);
				break;
			case 2:
				cout<<"\nenter the string to search..";
				cin>>key;
				temp=H.search(key);
				if(temp == NULL){
					cout<<"\nelement not found..\n";
				}
				else{
					cout<<"\nelement found..\n";
				}
				break;
			case 3:
				cout<<"\nenter the string to delete..";
				cin>>key;
				H.del(key);
				break;
			case 4:
				cout<<"\nenter the value of array u want to print...";
				int z;
				cin>>z;
				H.print(z);
				break;
			case 5:
				i=1;
				break;
			default:
				cout<<"\nenter proper choice...\n";
				break;
		}
	}
	return 0;
}