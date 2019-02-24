/*
//dsa-lab submission-3
//red-black tree with insert and search function...
//tutor shoban babu sir
//done by--A.Giri Prasad...
//es14btech11002...
//compiled and runned in mac terminal...
*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
struct node{
	int info;
	int col;		//consider col=0 for red..and col= 1 for black;
	node *lc,*rc,*p;
};
class Rbt{
public:
	node *root,*cur;
	Rbt(){
		root=NULL;
	}
   node *search(int num){			//normal bst search function....
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
	void insert(int num){				//normal bst insert
		if (root==NULL){
			root=new node;
			root->info=num;
			root->col=1;				//since root node is always black....
			return;
		}
		else{
			put(root,num);
			recolor(num);
		}
	}
	void recolor(int num){				//recouring function after inserting node in bst...
		node *x,*pa,*g,*u;
		x=search(num);
		if(x==root){
			x->col=1;
			x=NULL;
			return;
		}
		pa=x->p;
		if(pa->col!=1){
			g=pa->p;
			if(g->lc==pa)
				u=g->rc;
			else
				u=g->lc;
			if(u!=NULL){
				if(u->col==0){			//uncle red.....
				u->col=1;
				pa->col=1;
				g->col=0;
				recolor(g->info);
				}
				else{					//uncle black....
					if(g->lc==pa && pa->lc==x){				//ll-case
						ll(x,pa,g,u);
						return;
					}
					if(g->lc==pa && pa->rc==x){				//lr-case
						lr(x,pa,g,u);
						return;
					}
					if(g->rc==pa && pa->rc==x){				//rr-case
						rr(x,pa,g,u);
						return;
					}
					if(g->rc==pa && pa->lc==x){				//rl-case
						rl(x,pa,g,u);
						return;
					}
				}
			}
			else{					//uncle black....
					if(g->lc==pa && pa->lc==x){				//ll-case
						ll(x,pa,g,u);
						return;
					}
					if(g->lc==pa && pa->rc==x){				//lr-case
						lr(x,pa,g,u);
						return;
					}
					if(g->rc==pa && pa->rc==x){				//rr-case
						rr(x,pa,g,u);
						return;
					}
					if(g->rc==pa && pa->lc==x){				//rl-case
						rl(x,pa,g,u);
						return;
					}
			}
		}
		return;
	}
	void ll(node *x,node *pa,node *g,node *u){
		rrot(g);
		g->col=g->col + pa->col;
		pa->col=g->col - pa->col;
		g->col=g->col - pa->col;
		g=pa=x=u=NULL;
		return;
	}
	void lr(node *x,node *pa,node *g,node *u){
		lrot(pa);
		ll(pa,x,g,u);
	}
	void rr(node *x,node *pa,node *g,node *u){
		lrot(g);
		g->col=g->col + pa->col;
		pa->col=g->col - pa->col;
		g->col=g->col - pa->col;
		g=pa=x=u=NULL;
		return;
	}
	void rl(node *x,node *pa,node *g,node *u){
		rrot(pa);
		rr(pa,x,g,u);
	}
	void lrot(node *aa){			//left rotation
		node *ab,*ap;
		ab=aa->rc;
		ap=aa->p;
		if(ap!=NULL){
			if(aa == ap->lc){
				ap->lc=ab;
			}
			else{
				ap->rc=ab;
			}
			ab->p=ap;
		}
		else{
			ab->p=NULL;
			root=ab;
		}
		aa->rc=ab->lc;
		if(aa->rc != NULL)
			aa->rc->p=aa;
		ab->lc=aa;
		aa->p=ab;

	}
	void rrot(node *aa){			//right rotation
		node *ab,*ap;
		ab=aa->lc;
		ap=aa->p;
		if(ap!=NULL){
			if(aa == ap->lc){
				ap->lc=ab;
			}
			else{
				ap->rc=ab;
			}
			ab->p=ap;
		}
		else{
			ab->p=NULL;
			root=ab;
		}
		aa->lc=ab->rc;
		if(aa->lc != NULL)
			aa->lc->p=aa;
		ab->rc=aa;
		aa->p=ab;
	}
	void put(node *tree,int num){				//used in insert function...normal bst insert
		if(tree->info==num){
			cout<<"The number already exist...\n";
			return;
		}
		else{
			if(tree->info > num){
				if(tree->lc ==NULL){
					cur=new node;
					cur->info=num;
					cur->col=0;
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
					cur->col=0;
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
	void display(node *ptr, int level){			///for verification purpose...
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
	   		 if(ptr->col==1)
	   		 	cout<<".";
        	cout<<ptr->info;
        	display(ptr->lc, level+1);
   		 }
	}
};
int main(){
	Rbt A;
	int i,j,k=1;
	while(k==1){
		cout<<"\nenter 1 for insertion in rbt and 2 for exit..3.search..4.display...\n";
		cin>>i;
		if(i==1){
		cout<<"\nenter the number to insert..\n";
		cin>>j;
		A.insert(j);
		//A.display(A.root,1);
		}
		else{
			if(i==2){
				k=0;
				
			}
			else{
				if(i==3){
					cout<<"\nenter element to search..\n";
					int z;
					cin>>z;
					node *ser;
					ser=A.search(z);
					if(ser==NULL)
						cout<<"\nnot found,,\n";
					else{
						cout<<"\nelement found  color of element is...\n";
						if(ser->col==1)
							cout<<"black\n";
						else
							cout<<"red\n";
					}
				}
				else{
					if(i==4)
					{
						cout<<"\nconsidered if red colour printed only number and if black print '.' infront of number..\n";
						A.display(A.root,1);

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
