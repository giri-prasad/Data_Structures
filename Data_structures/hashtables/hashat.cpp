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
const int arrsize=4;
struct node
{
	int a,b;
	string value;
};
node arrstrt[size];
int arr2d[arrsize],num=0;
class hashat{
public:
	hashat(){								//constructor....
		int i;
		for(i=0;i<size;i++){
			arrstrt[i].a =0;
			arrstrt[i].b=0;
		}
		for(i=0;i<arrsize;i++){
			arr2d[i]=0;
		}
	}
	int hash(string key){
		int i,j,k,sum=0;
		i=key.length();
		for(j=0;j<i;j++){
			k=key[j];
			sum=sum+k;
		}
		sum=sum % arrsize;
		return sum;
	}
	int search(string key){
		int sum=hash(key);
		if(arr2d[sum]==0){
			return -1;
		}
		else{
			int i;
			i=arr2d[sum]-1;
			while(arrstrt[i].b != 0){
				if(arrstrt[i].value == key){
					//cout<<i<<endl;		//
					return i;
				}
				i=arrstrt[i].b-1;
			}
			if(arrstrt[i].value == key){
				//cout<<i<<endl;		//
				return i;
			}

		}
		return -1;
	}
	void insert(string key){
		int sum=hash(key);
		if(arr2d[sum] == 0){
			int i;
			for(i=0;i<size;i++){
				if(arrstrt[i].a == 0)
					break;
			}
			arr2d[sum]=i+1;
			arrstrt[i].a=1;
			arrstrt[i].value=key;
			num=num+1;
		}
		else{
			int j;
			j=arr2d[sum]-1;
			while(arrstrt[j].b != 0){
				j=arrstrt[j].b - 1;
			}
			int k;
			for(k=0;k<size;k++){
				if(arrstrt[k].a == 0)
					break;
			}
			arrstrt[j].b=k+1;
			arrstrt[k].a=1;
			arrstrt[k].value=key;
			num=num+1;
		}
	}
	void del(string key){
		int sum=hash(key);
		int i;
		i=search(key);
		if(i==-1){
			cout<<"\nno element to delete\n";
			return;
		}
		if(arr2d[sum]==i+1){			//first ele in a key/...
			if(arrstrt[i].b==0){
				arrstrt[i].a=0;
				arr2d[sum]=0;
				num--;
				return;
			}
			else{
				arr2d[sum]=arrstrt[i].b;
				arrstrt[i].a=0;
				arrstrt[i].b=0;
				num--;
				return;
			}
		}
		else{
				int j;
				j=arr2d[sum]-1;
				while(arrstrt[j].b != i+1){
					j=arrstrt[j].b -1;
				}
				arrstrt[j].b=arrstrt[i].b;
				arrstrt[i].b=0;
				arrstrt[i].a=0;
				num--;
				return;
		}
	}
	void print(int z){
		if(z >= arrsize || z < 0){
			cout<<"\nenter proper value of array\n";
			return;
		}
		else{
			int i;
			if(arr2d[z] == 0){
				cout<<"\nno elements in this key..\n";
				return;
			}
			i=arr2d[z]-1;
			//		cout<<i+1<<endl;			//
			while(arrstrt[i].b != 0){
				cout<<arrstrt[i].value<<endl;
				//		cout<<arrstrt[i].b<<endl;			//
				i=arrstrt[i].b -1;
			}
			cout<<arrstrt[i].value<<endl;
			//		cout<<arrstrt[i].b<<endl;			//
			return;
		}
	}
};
int main(){
	hashat H;
	int i=0,j,y;
	string key;
	while(i==0){
		cout<<"\n1.insert..2.search..3.delete..4.print.....5.exit...\nenter your choice....";
		cin>>j;
		switch(j){
			case 1:
				cout<<"\nenter the string to insert..";
				cin>>key;
				if(num == size){
					cout<<"\nu cant enter more elements...\n";
					break;
				}
				H.insert(key);
				//cout<<num<<endl;
				break;
			case 2:
				cout<<"\nenter the string to search..";
				cin>>key;
				y=H.search(key);
				if(y==-1){
					cout<<"\n no element..\n";
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