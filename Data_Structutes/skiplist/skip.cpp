/*
//assignment submission 7
//skip list...
//prof..shoban babu..
//ta .. shalini jain..
//student name A.giir  prasad..
//es14btech11002.....
//compiled  on mac terminal....
*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct node{
	int level,value;
	node *down,*next,*up,*prev;
}*head,*cur,*base;

int height,i;

class skip{
public:

	skip(){				//constructor...
		head=NULL;
		height=0;
	}

	void insert(int data,int lev){
		if(head==NULL){			//initially when no elements in list
			head=new node;
			head->level=1;
			base=head;
			height++;
			head->next=new node;
			head->next->prev=head;
			head->next->value=data;
			head->next->level=head->level;
		}
		else{
			if(height < lev){			//increasing the level..
				head->up=new node;
				head->up->down=head;
				head=head->up;
				height++;
				head->level=height;
				head->next=new node;
				head->next->prev=head;
				head->next->value=data;
				head->next->level=head->level;
				node *yy;
				yy=head->down->next;
				while(yy!=NULL){
					if(yy->value == data){
						yy->up=head->next;
						head->next->down=yy;
					}
					yy=yy->next;
				}
				yy=NULL;
				delete yy;
			}
			else{
				node *temp,*tem;
				temp=base;
				while(temp->up != NULL){
					if(temp->level == lev){
						break;
					}
					temp=temp->up;
				}
				if(lev==1){
					node *pt;
					pt=base->next;
					while(pt != NULL){			//cheking for exsistence of element..
						if(pt->value == data){
							cout<<"\nelement already exists..\n";
							pt=NULL;
							delete pt;
							return;
						}
						pt = pt->next;
					}
					pt=NULL;
					delete pt;
				}
				tem=temp->down;
				node *tt,*t;
				tt=temp;
				while(data > tt->next->value){
					tt=tt->next;
					if(tt->next == NULL)
						break;
				}
				if(tt->next == NULL){	//inserting at end of list..
					tt->next=new node;
					tt->next->prev=tt;
					tt->next->level=tt->level;
					tt->next->value=data;
					tt=tt->next;
				}
				else{					//inserting at non end of list
					node *te=tt->next;
					tt->next=new node;
					tt->next->prev=tt;
					tt->next->level=tt->level;
					tt->next->value=data;
					tt->next->next=te;
					te->prev=tt->next;
					te=NULL;
					delete te;
					tt=tt->next;
				}
				if(tem!=NULL){			//linking for upper level to lower level..
					t=tem->next;
					while(t->value != data){
						t=t->next;
					}
					tt->down=t;
					t->up=tt;
				}
				temp=NULL;
				tem=NULL;
				t=tem;
				tt=t;
				delete t;
				delete tt;
				delete temp;
				delete tem;
			}
		}
		i=rand()%2;		//rand function for coin tossing..
		if(i==0){
			lev++;
			insert(data,lev);
			return;
		}
		return;
	}

	void del(int data){		//delete function 
		node *tt,*t,*temp;
		tt=search(data);
		if(tt==NULL){		//searching the element..
			cout<<"\n no elementfound to delete..\n";
			return;
		}
		while(tt->up != NULL){
			tt=tt->up;
		}
		while(tt != NULL){		//loop to delete recursivelyy..
			t=tt->down;
			if(tt->next==NULL){
				temp=tt->prev;
				temp->next=NULL;
				tt->prev=NULL;
				tt->down=NULL;
				if(t!=NULL)
					t->up=NULL;
				node *tem=tt;
				tt=temp;
				delete tem;
			}
			else{
				temp=tt->prev;
				temp->next=tt->next;
				temp=tt->next;
				temp->prev=tt->prev;
				temp=temp->prev;
				tt->prev=NULL;
				tt->next=NULL;
				tt->down=NULL;
				if(t!=NULL)
					t->up=NULL;
				node *tem=tt;
				tt=temp;
				delete tem;
			}
			if(tt->prev == NULL && tt->next==NULL){
				node *tem;
				tem=tt;
				if(tt==base){
					head=NULL;
					base=NULL;
					height=0;
					tt=NULL;
					delete tem;
				}
				else{
					head=tt->down;
					head->up=NULL;
					tt->down=NULL;
					tt=NULL;
					height--;
					delete tem;
				}
			}
			tt=t;
		}
		tt=NULL;
		t=tt;
		temp=t;
		delete tt;
		delete t;
		delete temp;
		return;
	}

	node *search(int data){	//searching of element...
		if(base == NULL)
			return NULL;
		node *tt;
		tt=base->next;
		while(tt != NULL){
			if(tt->value == data){
				return tt;
			}
			tt=tt->next;
		}
		return NULL;
		while(tt != NULL){		//loop to search recursivelyy..			
			node *temp,*t;
			t=tt->down;
			if(tt->next==NULL){
				temp=tt->prev;
				temp->next=NULL;
				tt->prev=NULL;
				tt->down=NULL;
				if(t!=NULL)
					t->up=NULL;
				node *tem=tt;
				tt=temp;
				return tem;
			}
			else{
				temp=tt->prev;
				temp->next=tt->next;
				temp=tt->next;
				temp->prev=tt->prev;
				temp=temp->prev;
				tt->prev=NULL;
				tt->next=NULL;
				tt->down=NULL;
				if(t!=NULL)
					t->up=NULL;
				node *tem=tt;
				tt=temp;
				return tem;
			}
		}
		return NULL;
	}

	void display(){		//function to display the list...
		if(head==NULL){
			cout<<"\nno elements..\n";
			return;
		}
		node *ter,*terx;
		ter=head;
		terx=head->next;
		int a;
		for(a=0;a<height;a++){
			while(terx!=NULL){
				cout<<terx->value<<"   ";
				terx=terx->next;
			}
			ter=ter->down;
			if(ter==NULL){
				terx=ter;
				delete ter;
				delete terx;
				return;
			}
			terx=ter->next;
			cout<<endl;
		}
		ter=NULL;
		terx=ter;
		delete ter;
		delete terx;
		return;
	}
};

int main(){
	skip A;
	int i=0,j,y;
	int data;
	srand((unsigned)time(0));		//timer for rand function..
	while(i==0){
		cout<<"\n1.insert..2.search..3.delete..4.print.....5.exit...\nenter your choice....";
		cin>>j;
		switch(j){
			case 1:
				cout<<"\nenter the integer to insert..";
				cin>>data;
				A.insert(data,1);
				break;
			case 2:
				cout<<"\nenter the int to search..";
				cin>>data;
				node *ser;
				ser=A.search(data);
				if(ser==NULL)
					cout<<"\nno element found..\n";
				else
					cout<<"\nelement found..\n";
				break;
			case 3:
				cout<<"\nenter the int to delete..";
				cin>>data;
				A.del(data);
				break;
			case 4:
				A.display();
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