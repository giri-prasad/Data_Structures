#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;
struct node 		//struct node.....
{
    float xco,yco;
    node *p,*lc,*rc;
};
float minx,miny,z;			//global variables...
float dist;
class kd{
public:
	node *root,*cur;
	kd(){				//initialization of class....
		z=0;
		dist=0;
		root=NULL;
	}
	void insert(float x,float y){				//insert function for inserting the points...
		if (root==NULL){			//inserting the root...
			root=new node;
			root->xco=x;
			root->yco=y;
			return;
		}
		else{
			putx(root,x,y);	
			return;
		}
	}
	void putx(node *tree,float x,float y){			//while inserting for checking the x co-ordinate..
		if(x < tree->xco){
			if(tree->lc==NULL){
				tree->lc=new node;
				tree->lc->p=tree;
				tree->lc->xco=x;
				tree->lc->yco=y;
				return;
			}
			else{
				tree=tree->lc;
				puty(tree,x,y);
				return;
			}
		}
		else{
			if(x==tree->xco && y==tree->yco){				//if point already exists...
				cout<<"\npoint already exist...\n";
				return;
			}
			else{
				if(tree->rc==NULL){				//inserting node...
					tree->rc=new node;
					tree->rc->p=tree;
					tree->rc->xco=x;
					tree->rc->yco=y;
					return;
				}
				else{
					tree=tree->rc;
					puty(tree,x,y);
					return;
				}
			}
		}
	}

	void puty(node *tree,float x,float y){			//while inserting for checking the y co-ordinate..
		if(y < tree->yco){
			if(tree->lc==NULL){			//inserting node...
				tree->lc=new node;
				tree->lc->p=tree;
				tree->lc->xco=x;
				tree->lc->yco=y;
				return;
			}
			else{
				tree=tree->lc;
				putx(tree,x,y);
				return;
			}
		}
		else{
			if(y==tree->yco && x==tree->xco){				//if point already exists...
				cout<<"\npoint already exist...\n";
				return;
			}
			else{
				if(tree->rc==NULL){
					tree->rc=new node;
					tree->rc->p=tree;
					tree->rc->xco=x;
					tree->rc->yco=y;
					return;
				}
				else{
					tree=tree->rc;
					putx(tree,x,y);
					return;
				}
			}
		}
	}

void display(node *ptr, float level){			//prints the whole tree as it is....for verification porpose,...
    float i;
    if (ptr != NULL)
    {
        display(ptr->rc, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"     	  ";
	    }
        cout<<ptr->xco<<","<<ptr->yco;
        display(ptr->lc, level+1);
    }
    cout<<endl;
}

void nearestneighbour(node *ptr,float x,float y){				//finding the nearest neigbour...
	float a;
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        nearestneighbour(ptr->lc,x,y);
        nearestneighbour(ptr->rc,x,y);
        //cout<<ptr->xco<<","<<ptr->yco<<"     ";
        a = sqrt((x - ptr->xco) * (x - ptr->xco) + (y-ptr->yco) *(y-ptr->yco));
        if(z==0){
        	z=1;
        	minx=ptr->xco;
        	miny=ptr->yco;
        	dist=a;
        }
        else{
        	if(a<dist){
        		minx=ptr->xco;
        		miny=ptr->yco;
        		dist=a;
        	}
        }
    }
}

};

int main(){
	kd A;				//declaration of object....
	float x,y,k=1;int i;
	while(k==1){		//while loop for recursive...
		cout<<"\nenter 1 for insertion and 2 for search nearestneighbour...3.for display...4 for exit...\n";
		cin>>i;
		switch(i){
			case 1:
				cout<<"\nenter the point to insert...\nx-co-ordinate......";
				cin>>x;
				cout<<"\ny-co-ordinate.....";
				cin>>y;
				A.insert(x,y);		//calling insert function..
				break;
			case 2:
				cout<<"\n enter the point to search nearest point...\nx-co-ordinate.......";
				cin>>x;
				cout<<"\ny-co-ordinate.....";
				cin>>y;
				A.nearestneighbour(A.root,x,y);			//calling the nearestpoint function..
				if(A.root != NULL)
					cout<<"\nthe nearest nearestneighbour is...."<<minx<<","<<miny<<" -----dist is..."<<dist<<endl;
				z=0;
				break;
			case 3:
				A.display(A.root,1);		//calling the display function..
				break;
			case 4:
				k=0;
				break;
			default:
				cout<<"\nenter proper choice....";
				break;
		}
	}
return 0;
}