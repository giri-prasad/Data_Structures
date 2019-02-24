#include <iostream>
#include <sstream>
#include <string>
using namespace std;
struct node
{
    int info;
    node *p,*lc,*rc;
};

class bst{
public:
	node *root,*cur;
	bst(){
		root=NULL;
	}
	void insert(int num){
		if (root==NULL){
			root=new node;
			root->info=num;
			return;
		}
		else{
			put(root,num);

			
		}
	}
	void put(node *tree,int num){
		if(tree->info==num){
			cout<<"The number already exist...\n";
			return;
		}
		else{
			if(tree->info > num){
				if(tree->lc ==NULL){
					cur=new node;
					cur->info=num;
					cur->p=tree;
					tree->lc=cur;
					cur=NULL;
					return;
				}
				else{
					put(tree->lc,num);
				}

			}
			else{
				if(tree->info < num){
				   if(tree->rc ==NULL){
					cur=new node;
					cur->info=num;
					cur->p=tree;
					tree->rc=cur;
					cur=NULL;
					return;
				   }
				 else{
					put(tree->rc,num);
				}
			}

		}
	}
}
node *search(int num){
	node *temp;
	temp=root;
	while(num!=temp->info){
		if(num>temp->info){
			if(temp->rc==NULL){
				cout<<"no such element..\n";
				return NULL;
			}
			else{
				temp=temp->rc;
			}
		}
		else{
			if(temp->lc==NULL){
				cout<<"no such element..\n";
				return NULL;
			}
			else{
				temp=temp->lc;
			}
		}
	}
	return temp;
}
void dela(node *temp){
	node *tem;
	if(temp==root){
		root=NULL;
		delete temp;
		cout<<"no more elements.\n";
		return;
	}
	tem=temp->p;
	if(tem->lc==temp){
		tem->lc=NULL;
		delete temp;
		return;
	}
	else{
		tem->rc=NULL;
		delete temp;
		return;
	}
}
void dell(node *temp){
	node *tem;
	if(temp==root){
		tem=temp->lc;
		tem->p=NULL;
		temp->lc=NULL;
		root=tem;
		delete temp;
		return;
	}
	tem=temp->p;
	if(temp==tem->lc){
		tem->lc=temp->lc;
		tem=temp->lc;
		tem->p=temp->p;
		delete temp;
		return;
	}
	else{
		tem->rc=temp->lc;
		tem=temp->lc;
		tem->p=temp->p;
		delete temp;
		return;
	}
}
void delr(node *temp){
	node *tem;
	if(temp==root){
		tem=temp->rc;
		tem->p=NULL;
		temp->rc=NULL;
		root=tem;
		delete temp;
		return;
	}
	
	tem=temp->p;
	if(temp==tem->lc){
		tem->lc=temp->rc;
		tem=temp->rc;
		tem->p=temp->p;
		delete temp;
		return;
	}
	else{
		tem->rc=temp->rc;
		tem=temp->rc;
		tem->p=temp->p;
		delete temp;
		return;
	}
}
void delb(node *temp){
	node *tem,*find;
	tem=temp->lc;
	find=temp->rc;
	while(find->lc!=NULL){
		find=find->lc;
	}
	tem->p=find;
	find->lc=tem;
	temp->lc=NULL;
	find=NULL;
	tem=NULL;
	delr(temp);
}
void del(int j){
	node *temp;
	temp=search(j);
	if(temp==NULL){
		cout<<"no element to delete.\n";
		return;
	}
	if(temp->rc==NULL && temp->lc==NULL){
		dela(temp);
		return;
	}
	if(temp->rc==NULL && temp->lc!=NULL){
		dell(temp);
		return;
	}
	if(temp->rc!=NULL && temp->lc==NULL){
		delr(temp);
		return;
	}
	if(temp->lc!=NULL &&  temp->rc!=NULL){
		delb(temp);
		return;
	}
	return;
}

void display(node *ptr, int level){
    int i;
    if (ptr != NULL)
    {
        display(ptr->rc, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
	    }
        cout<<ptr->info;
        display(ptr->lc, level+1);
    }
}

};

int main(){
	bst A;
	int i,j,k=1;
	while(k==1){
		cout<<"\nenter 1 for insertion and 2 for deletion..3 for exit..4.search..\n";
	cin>>i;
	if(i==1){
		cout<<"\nenter the number to insert..\n";
		cin>>j;
		A.insert(j);
		A.display(A.root,1);
	}
	else{
		if(i==2){
			cout<<"\nenter the number to delete..\n";
			cin>>j;
			
			A.del(j);

		}
		else{
			if(i==3){
				k=0;
				
			}
			else{
				if(i==4){
					cout<<"\nenter element to search..\n";
					int z;
					cin>>z;
					node *ser;
					ser=A.search(z);
					if(ser==NULL)
						cout<<"\nnot found,,\n";
				}
				else{
				cout<<"\nenter proper choice..\n";
			}
			}
		}
	}
	}
return 0;
}