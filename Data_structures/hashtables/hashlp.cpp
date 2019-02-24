/*
//A.giri prasad.
//es14btech11002
//dsa assignment submission 6
//prof.shoban babu
//TA.shalini jain.
//compiled and runned on mac terminal...
*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
const int size=10;
struct node{						//struct...
	int a;
	string value;
};
node arrstrt[size];					//arry of structs........
int num;							//for count porpose....
class hashlp{
public:
	hashlp(){						//constructor...for initilization..				
		int i;
		for(i=0;i<size;i++){
			arrstrt[i].a=0;
		}
		num=0;
	}
	int hash(string key){			//hash function....
		int i,j,k,sum=0;
		i=key.length();
		for(j=0;j<i;j++){
			k=key[j];
			sum=sum+k;
		}
		sum=sum % size;
		return sum;
	}
	void insert(string key){		//inserting elements ..
		if(num==size){
			cout<<"\nyou can't insert more elements..\n";
			return;
		}
		int sum,i,j;
		sum=hash(key);
		for(i=sum;i<sum+size;i++){			//loop searches for quadratic positions to insert...
			j=i;
			j=j%size;
			if(arrstrt[j].a!=1){
				arrstrt[j].value=key;
				arrstrt[j].a=1;
				num++;
				return;
			}
		}
	}
	void del(string key){			//deleting elements..
		if(num==0){
			cout<<"\nno elements to delete...\n";
			return;
		}
		int sum,i,j;
		sum=hash(key);
		for(i=sum;i<(sum+size);i++){		//loop searches for quadratic positions to delete...
			j=i;
			j=j%size;
			if(arrstrt[j].a==1){
				if(arrstrt[j].value == key){
					cout<<"\nelement to be deleted found...";
					arrstrt[j].a=-1;
					num--;
					cout<<"&   deleted...\n";
					return;
				}
			}
		}
		cout<<"\nelement to be deleted not found..\n";
		return;
	}
	void search(string key){			//searching elements...
		if(num==0){
			cout<<"\nno elements to search..\n";
			return;
		}
		int sum,i,j;
		sum=hash(key);
		for(i=sum;i<(sum+size);i++){			//loop searches for quadratic positions to search...
			j=i;
			j=j%size;
			if(arrstrt[j].a==0){
				cout<<"\nelement not found..\n";
				return;
			}
			if(arrstrt[j].a==1){
				if(arrstrt[j].value == key){
					cout<<"\nelement found...\n";
					return;
				}
			}
											//cout<<j<<endl;////////
		}
		cout<<"\nelement not found..\n";
		return;
	}
	void print(){					//printing all table...
		int i;
		for(i=0;i<size;i++){
			if(arrstrt[i].a==1){
				cout<<arrstrt[i].value<<endl;
			}
			else{
				cout<<"NULL"<<endl;
			}
		}
		return;
	}
};
int main(){
	hashlp H;
	int i=0,j;
	string key;
	node *temp;
	while(i==0){			//loop to itirate choices.....
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
				H.search(key);
				break;
			case 3:
				cout<<"\nenter the string to delete..";
				cin>>key;
				H.del(key);
				break;
			case 4:
				H.print();
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