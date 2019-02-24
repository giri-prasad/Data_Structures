/*
//B-Tree..assignment.of 5way tree..this works only for any odd way tree...
*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
const int MAX=4,MIN=2;						//bcuz it's a 5 way tree...		
struct node{
	int key[MAX+1];
	node *p[MAX+2];							//pointer array
	node *par;
	int nkeys,nptrs;
};
class btree{
public:
	node *root,*cur;
	btree(){
		root=NULL;
	}
	void bubble(node *cur){
		int i,j,n;
		n=cur->nkeys;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if((cur->key[i])>(cur->key[j])){
					cur->key[i]=cur->key[i] + cur->key[j];
					cur->key[j]=cur->key[i] - cur->key[j];
					cur->key[i]=cur->key[i] - cur->key[j];
				}
			}
		}
		/*
		int k;									//for verifiacation porpose... :P
		for(k=0;k<n;k++) {
			cout<<cur->key[k]<<"   ";
		} 
		cout<<"\n";
		*///1 1 1 12 1 8 1 2 1 25 1 6 1 14 1 28 1 17 1 7 1 52 1 16 1 48 1 68 1 3 1 26 1 29 1 53 1 55 1 45 
	}
	void split(node *cur){
		node *temp;
		temp=new node;
		int n,mid,a,b;
		n=MAX+1;mid=n/2;
		a=mid+1;
		for(b=0;b<MIN;b++){
			temp->key[b]=cur->key[a];
			a++;
			(temp->nkeys)++;
			(cur->nkeys)--;
		}
		if(cur->nptrs != 0){
				cur->nptrs=mid+1;
				int z;
				for(z=0;z<=mid;z++){
					temp->p[z]=cur->p[z+(mid+1)];
					temp->p[z]->par=temp;					//changing the parent...****
					(temp->nptrs)++;
					cur->p[z+(mid+1)]=NULL;					
				}
		}
		if(cur->par==NULL){
			node *temp1;
			temp1=new node;
			root=temp1;
			temp1->key[0]=cur->key[mid];
			(cur->nkeys)--;
			(temp1->nkeys)++;
			cur->par=temp1;
			temp->par=temp1;
			temp1->p[0]=cur;temp1->nptrs++;
			temp1->p[1]=temp;temp1->nptrs++;
		}
		else{								 
			node *tem;
			tem=cur->par;
			if(cur->key[mid] > tem->key[(tem->nkeys)-1]){
				tem->key[tem->nkeys]=cur->key[mid];
				(tem->nkeys)++;
				(cur->nkeys)--;
				tem->p[tem->nptrs]=temp;
				(tem->nptrs)++;
				temp->par=tem;							
				if(tem->nkeys == MAX+1){
					 split(tem);
				}
				return;
			}
			else{
				int c,d,e,f;
				c=(tem->nkeys)-1;
				f=(tem->nptrs)-1;
				for(d=0;d<=c;d++){
					if( cur->key[mid] < tem->key[d] ){
						for(e=c;e>=d;e--){
							tem->key[e+1]=tem->key[e];
						}
						tem->key[d]=cur->key[mid];
						(tem->nkeys)++;
						(cur->nkeys)--;							
						for(e=f;e>d;e--){
							tem->p[e+1]=tem->p[e];
						}
						tem->p[d+1]=temp;
						temp->par=tem;							
						(tem->nptrs)++;
						if(tem->nkeys == MAX+1){
							split(tem);
						}
						return;
					}
				}
			}
		}
	}
	void insert(int a){
		if(root==NULL){
			root=new node;
			root->key[0]=a;
			root->nkeys++;
			return;
		}
		else{
			cur=root;
			int b,c,d;
			while((cur->nptrs)!=0){
				b=cur->nkeys;
				for(c=0;c<b;c++){
					if(a==(cur->key[c])){
						cout<<"\nElement already exists..\n";
						return;
					}
				}
				for(c=0;c<b;c++){
						if(a>(cur->key[b-1])){
							cur=cur->p[b];
							break;
						}	
						else if(a<(cur->key[c])){
							cur=cur->p[c];
							break;
						}			
				}
			}
			d=cur->nkeys;
			for(c=0;c<d;c++){
				if(a==(cur->key[c])){
					cout<<"\nElement already exists..\n";
					return;
				}
			}
			cur->key[cur->nkeys]=a;
			cur->nkeys++;
			bubble(cur);
			if(cur->nkeys==(MAX+1)){
				split(cur);
				return;
			}
			return;
		}
	}
	node *search(int a){
		if(root==NULL){
			return NULL;
		}
		else{
			cur=root;
			int b,c,d;
			while((cur->nptrs)!=0){
				b=cur->nkeys;
				for(c=0;c<b;c++){
					if(a==(cur->key[c])){
						//cout<<"\nelement found\n";
						return cur;
					}
				}
				for(c=0;c<b;c++){
						if(a>(cur->key[b-1])){
							cur=cur->p[b];break;
						}
						else if(a<(cur->key[c])){
							cur=cur->p[c];break;
						}
				}
			}
			d=cur->nkeys;
			for(c=0;c<d;c++){
				if(a==(cur->key[c])){
					//cout<<"\nelement found\n";
					return cur;
				}
			}
			return NULL;
		}
	}
	void la(node *ser,int a){
		int i,j;
		for(i=0;i<(ser->nkeys);i++){
			if(a ==ser->key[i]){
				for(j=i;j<((ser->nkeys)-1);j++){
					ser->key[j]=ser->key[j+1];
				}
				(ser->nkeys)--;
				break;
			}
		}
		return;
	}
	void lb(node *ser,node *serp,int a,int i){		//right sibbling has more than MIN case..
		int j,k;
		for(j=0;j<(ser->nkeys);j++){
			if(ser->key[j] == a){				//j == finding aray position of a;
				break;
			}
		}
		ser->key[j] = serp->key[i];
		serp->key[i]=serp->p[i+1]->key[0];
		bubble(ser);
		for(k=0;k<(serp->p[i+1]->nkeys)-1;k++){
			serp->p[i+1]->key[k]=serp->p[i+1]->key[k+1];
		}
		(serp->p[i+1]->nkeys)--;
	}
	void lc(node *ser,node *serp,int a,int i){			//left sibbling has more than MIN case..
		int j;
		for(j=0;j<(ser->nkeys);j++){
			if(ser->key[j] == a){				//j == finding aray position of a;
				break;
			}
		}
		ser->key[j] = serp->key[i-1];
		serp->key[i-1]=serp->p[i-1]->key[(serp->p[i-1]->nkeys)-1];
		bubble(ser);
		(serp->p[i-1]->nkeys)--;
	}
	void ld(node *ser,node *serp,int a,int i){				//merge case....
		int j,k;
		for(j=0;j<(ser->nkeys);j++){
			if(ser->key[j] == a){				//j == finding aray position of a;
				break;
			}
		}
		if(i == (serp->nptrs)-1){
			ser->key[j]=serp->key[i-1];
			bubble(ser);
			(serp->nkeys)--;
			int l=0,m;
			m=(serp->p[i-1]->nkeys);
			for(k=m;k<MAX;k++){
				serp->p[i-1]->key[k]=ser->key[l];
				l++;
				(serp->p[i-1]->nkeys)++;
			}
			node *t;
			t=ser;
			ser=NULL;
			serp->p[i]=NULL;
			delete t;
			(serp->nptrs)--;
		}
		else{
			ser->key[j]=serp->key[i];
			bubble(ser);
			for(k=i;k<(serp->nkeys)-1;k++){
				serp->key[k]=serp->key[k+1];
			}
			(serp->nkeys)--;
			int l=0,m;
			m=(ser->nkeys);
			for(k=m;k<MAX;k++){
				ser->key[k]=serp->p[i+1]->key[l];
				l++;
				(ser->nkeys)++;
			}
			node *t;
			t=serp->p[i+1];
			serp->p[i+1]=NULL;
			delete t;
			for(l=i+1;l<(serp->nptrs)-1;l++){
				serp->p[l]=serp->p[l+1];
			}
			serp->p[(serp->nptrs)-1]=NULL;
			(serp->nptrs)--;
		}
	}
	void borrowfromr(node *ser,node *serp,int i){
		node *t=serp->p[i+1];
		ser->key[ser->nkeys] = serp->key[i];
		serp->key[i]=t->key[0];
		(ser->nkeys)++;
		int j,k;
		j=t->nkeys;
		for(k=0;k<(j-1);k++){
			t->key[k]=t->key[k+1];
		}
		(t->nkeys)--;
		ser->p[ser->nptrs]=t->p[0];
		ser->p[ser->nptrs]->par=ser;
		(ser->nptrs)++;
		j=t->nptrs;
		for(k=0;k<(j-1);k++){
			t->p[k]=t->p[k+1];
		}
		t->p[j-1]=NULL;
		(t->nptrs)--;
		return;
	}
	void borrowfroml(node *ser,node *serp,int i){
		node *t=serp->p[i-1];
		ser->key[ser->nkeys]=serp->key[i-1];
		(ser->nkeys)++;
		bubble(ser);								//bubbing is done ehehehehe..:P
		serp->key[i-1]=t->key[(t->nkeys)-1];
		(t->nkeys)--;
		int j,k;
		j=ser->nptrs;
		for(k=(j-1);k>=0;k--){
			ser->p[k+1]=ser->p[k];
		}
		ser->p[0]=t->p[(t->nptrs)-1];
		t->p[(t->nptrs)-1]=NULL;
		ser->p[0]->par=ser;
		(ser->nptrs)++;
		(t->nptrs)--;
		return;
	}
	void mergetor(node *ser,node *serp,int i){			//merge ser's right to ser....
		node *t;
		t=serp->p[i+1];
		ser->key[ser->nkeys]=serp->key[i];
		int j,k;
		j=serp->nkeys;
		for(k=i;k<(j-1);k++){
			serp->key[k]=serp->key[k+1];
		}
		(serp->nkeys)--;
		(ser->nkeys)++;
		for(k=0;k<(t->nkeys);k++){
			ser->key[ser->nkeys]=t->key[k];
			(ser->nkeys)++;
		}
		j=t->nptrs;
		for(k=0;k<j;k++){
			ser->p[ser->nptrs]=t->p[k];
			ser->p[ser->nptrs]->par=ser;
			(ser->nptrs)++;
		}
		serp->p[i+1]=NULL;
		j=serp->nptrs;
		for(k=(i+1);k<(j-1);k++){
			serp->p[k]=serp->p[k+1];
		}
		serp->p[j-1]=NULL;
		delete t;
		if(serp->nkeys < MIN)
			lessmin(serp);
		return;
	}
	void mergetol(node *ser,node *serp,int i){			//merge ser to its left node...
		ser=serp->p[i-1];									//simple still now didn't get this thought..				
		i=i-1;												//for borrowl and others..
		mergetor(ser,serp,i);
		return;
	}
	void lessmin(node *ser){
		if(ser==root){
			if(ser->nkeys == 0){
				root=root->p[0];
				root->par=NULL;
				delete ser;
				return;
			}
			return;
		}
		else{
			node *serp;
			serp=ser->par;
			int i,j;
			j=serp->nptrs;
			for(i=0;i<j;i++){					//we got the pointer number of ser...
				if(serp->p[i] == ser)
					break;
			}
			if(i == 0){
				if(serp->p[i+1]->nkeys > MIN){
					borrowfromr(ser,serp,i);
					return;
				}
				else{
					mergetor(ser,serp,i);				//merge ser's right to ser....
					return;
				}
			}
			else{
				if(i == (serp->nptrs)-1){
					if(serp->p[i-1]->nkeys > MIN){
						borrowfroml(ser,serp,i);
						return;
					}
					else{
						mergetol(ser,serp,i);			//merge ser to its left node...
						return;
					}
				}
				else{
					if(serp->p[i+1]->nkeys > MIN){
						borrowfromr(ser,serp,i);
						return;
					}
					else{
						if(serp->p[i-1]->nkeys > MIN){
							borrowfroml(ser,serp,i);
							return;
						}
						else{
							mergetor(ser,serp,i);
							return;
						}
					}
				}
			}
		}
	}
	void le(node *ser,node *serp,int a,int i){		
		int j,k;
		for(j=0;j<(ser->nkeys);j++){
			if(ser->key[j] == a){				//j == finding aray position of a;
				break;
			}
		}
		if(i==(serp->nptrs)-1){
			ser->key[j]=serp->key[i-1];
			bubble(ser);
			(serp->nkeys)--;
			k=i-1;
			node *t;
			t=serp->p[k];
			k=ser->nkeys;int u;
			for(u=0;u<k;u++){
				t->key[(t->nkeys)]=ser->key[u];
				(t->nkeys)++;
				(ser->nkeys)--;
			}
			serp->p[i]=NULL;
			(serp->nptrs)--;
			delete ser;
		}
		else{
			ser->key[j]=serp->key[i];
			bubble(ser);
			int v;
			for(k=i;k<(serp->nkeys)-1;k++){
				serp->key[k]=serp->key[k+1];
			}
			(serp->nkeys)--;
			k=i+1;
			node *tt;
			tt=serp->p[k];
			k=tt->nkeys;
			for(v=0;v<k;v++){
				ser->key[(ser->nkeys)]=tt->key[v];
				(ser->nkeys)++;
				(tt->nkeys)--;
			}
			k=serp->nptrs;
			for(v=i+1;v<(k-1);v++){
				serp->p[v]=serp->p[v+1];
			}
			serp->p[(serp->nptrs)-1]=NULL;
			(serp->nptrs)--;
			delete tt;
		}
		lessmin(serp);
		return;
	}
	void del_leaf(node *ser,int a){
		if(ser->nkeys > MIN){
			la(ser,a);
			return;
		}
		else{
			node *serp;
			serp=ser->par;
			int i;								
			for(i=0;i<(serp->nptrs);i++){
				if((serp->p[i])==ser){				//i===pointer num of ser..
					break;
				}
			}
			if(i==0){					//ser is first pointer...so check for right sibling..
				if((serp->p[i+1]->nkeys) > MIN){
					lb(ser,serp,a,i);
					return;
				}
				else{
					if((serp->nkeys)>MIN){
						ld(ser,serp,a,i);
						return;
					}
					else{
						le(ser,serp,a,i);
						return;
					}
				}
			}
			else{
				if(i==(serp->nptrs)-1){					//ser is last pointer...so check for left sibling..
					if((serp->p[i-1]->nkeys) > MIN){
						lc(ser,serp,a,i);
						return;
					}
					else{
						if((serp->nkeys)>MIN){
							ld(ser,serp,a,i);
							return;
						}
						else{
							le(ser,serp,a,i);
							return;
						}
					}
				}
				else{
					if((serp->p[i+1]->nkeys) > MIN){
						lb(ser,serp,a,i);
						return;
					}
					else{
						if((serp->p[i-1]->nkeys) > MIN){
							lc(ser,serp,a,i);
							return;
						}
						else{
							if((serp->nkeys)>MIN){
								ld(ser,serp,a,i);
								return;
							}
							else{
								le(ser,serp,a,i);
								return;
							}
						}
					}
				}
			}
		}
	}
	void del_nonleaf(node *ser,int a){					//not yet done....
		int i,j;
		for(i=0;i<(ser->nkeys);i++){					//i==for finding a in ser...
			if(ser->key[i]==a)
				break;
		}
		node *suc,*prec;
		prec=ser->p[i];					//like previous generation/\....
		suc=ser->p[i+1];				//like next generation/\....
		while((suc->nptrs)!=0){
			suc=suc->p[0];
		}
		while((prec->nptrs)!=0){
			prec=prec->p[(prec->nptrs)-1];
		}
		if(suc->nkeys > MIN){
			ser->key[i]=suc->key[0];
			del_leaf(suc,suc->key[0]);
			return;
		}
		else{
			if(prec->nkeys > MIN){
				ser->key[i]=prec->key[(prec->nkeys)-1];
				del_leaf(prec,prec->key[(prec->nkeys)-1]);
				return;
			}
			else{
				ser->key[i]=suc->key[0];
				del_leaf(suc,suc->key[0]);
				return;
			}
		}
	}
	void del(int a){
		node *ser;
		ser=search(a);
		if(ser==NULL){
			cout<<"\n element not found..\n";
		}
		else{
			if(ser->nptrs == 0){
				if(ser==root){
					int j,k;
					for(j=0;j<(ser->nkeys);j++){
						if(a==ser->key[j])
							break;
					}
					for(k=j;k<(ser->nkeys)-1;k++){
						ser->key[k]=ser->key[k+1];
					}
					(ser->nkeys)--;
					if(ser->nkeys == 0){
						root=NULL;
						cout<<"\nno more elements.. root is NULL...\n";
					}
					return;
				}
				del_leaf(ser,a);
				return;
			}
			else{
				del_nonleaf(ser,a);
				return;
			}
		}
	}
};
int main(){
	btree A;
	int i,j,k=1;
   while(k==1){
		cout<<"\nenter 1 for insertion and 2 for deletion..3 for exit..4.search..\n";
	cin>>i;
	if(i==1){
		cout<<"\nenter the number to insert....";
		cin>>j;
		A.insert(j);
		//A.display(A.root);
	}
	else{
		if(i==2){
			cout<<"\nenter the number to delete....";
			cin>>j;
			A.del(j);
			//cout<<"\nnkeys in root.."<<A.root->nkeys<<endl;		//
			//cout<<"\nfirst value in root..."<<A.root->key[0]<<endl;	//
		}
		else{
			if(i==3){
				k=0;
				
			}
			else{
				if(i==4){
					cout<<"\nenter element to search....";
					int z;
					cin>>z;
					node *ser;
					ser=A.search(z);
					if(ser==NULL)
						cout<<"\nnot found,,\n";
					else
						cout<<"\nelement found..\n";
				}
				else{
				cout<<"\nenter proper choice.....";
			}
			}
		}
	}
   }
return 0;
}