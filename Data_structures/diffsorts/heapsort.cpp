
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int arr[50],ar[50],i,g,p;
class heap{
public:
	void insert(int num){
		if(i==0){
			arr[i]=num;
			i++;g++;
		}
		else{
			arr[i]=num;
			swapin(i);
			i++;g++;
		}
	}
	void swapin(int i){
		int j;
		j=(i+1)/2;		
		j=j-1;		//arr[j]=is parent,,,
		if(arr[j]<arr[i]){
			arr[j]=arr[j]+arr[i];
			arr[i]=arr[j]-arr[i];
			arr[j]=arr[j]-arr[i];
			swapin(j);
		}
		else{
			return;
		}
	}
	void delmax(){
		if(i==1){
			ar[0]=arr[0];
			return;
		}
		arr[p]=arr[p]+arr[i-1];
		arr[i-1]=arr[p]-arr[i-1];
		arr[p]=arr[p]-arr[i-1];
		ar[i-1]=arr[i-1];
		arr[i-1]=0;
		i=i-1;
		
		swapdel(p);
	}
	void swapdel(int p){
		int z;
		z=2*(p+1);
		if(arr[z-1]<arr[z] && arr[z]>arr[p]){
			arr[z]=arr[z]+arr[p];
			arr[p]=arr[z]-arr[p];
			arr[z]=arr[z]-arr[p];
			if(z<(i/2)){
				swapdel(z);
			}
		}
		else{
			if(arr[z-1]>arr[z] &&  arr[z-1]>arr[p]){
				arr[z-1]=arr[z-1]+arr[p];
			arr[p]=arr[z-1]-arr[p];
			arr[z-1]=arr[z-1]-arr[p];
			if((z-1)<(i/2)){
				swapdel(z-1);
			}
			}
		}
	}
};
int main(){
	heap H;
	int a=0,c;
	while(a==0){
		cout<<"1.insert..\n2.sort..\n3.print heapsort...\n4.EXIT...\n";
		int b;
		cin>>b;
		switch(b){
			case 1:
				cout<<"enter the num to insert in heap...\n";
				cin>>c;
				H.insert(c);
				break;
			case 2:
				for(int f;f<g;f++){
					H.delmax();
				}
				break;
			
			case 3:
				int d;
				for(d=0;d<g;d++){
					cout<<ar[d]<<"    ";
				}
				//cout<<ar[0];
				//cout<<arr[i];
				//cout<<"\n"<<i<<"\n";
				break;
			case 4:
				a=1;
				break;
			default:
				cout<<"wrong choice..\n";

		}
	}
}
