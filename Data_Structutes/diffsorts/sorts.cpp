#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Sorts{
public:
void insertion(){
int i,j,key;
cout<<"enter the num of elements.\n";
	int n;
	cin>> n;
	int arr[n];
	cout<<"entr the elements\n";
	for(int i;i<n;i++){
		cin>>arr[i];
	}
for(i=1;i<n;i++)
{
	key=arr[i];
	while(i>0 && arr[i-1]>key) {
		j=arr[i];
		arr[i]=arr[i-1];
	   arr[i-1]=j;
	   --i;
	}	
}
int k;
for(k=0;k<n;k++){
	
	cout<<arr[k]<<"  ";
}

cout<<"\n";
}
void bubble(){
int i,j,x;
cout<<"enter the num of elements.\n";
	int n;
	cin>> n;
	int arr[n];
	cout<<"entr the elements\n";
	for(int i;i<n;i++){
		cin>>arr[i];
	}
for(i=0;i<n;i++) {
	for(j=i+1;j<n;j++) {
		if(arr[i]>arr[j]) {
			x=arr[i];
			arr[i]=arr[j];
			arr[j]=x;
			
	}
}
}
int k;
for(k=0;k<n;k++) {
	
	cout<<arr[k]<<"   ";
} 

cout<<"\n";
}
void selection(){
cout<<"enter the num of elements.\n";
	int n;
	cin>> n;
	int arr[n];
	cout<<"entr the elements\n";
	for(int z;z<n;z++){
		cin>>arr[z];
	}
int i,j,x,min,k;
for(i=0;i<n;i++) {
	min=i;
	for(j=i+1;j<n;j++) {
		if(arr[min]>arr[j]) {
			min=j;
	}
	x=arr[min];
	arr[min]=arr[j];
	arr[j]=x;
}	}
for(k=(n-1);k>=0;k--) {
	
	cout<<arr[k]<<"  ";
}
cout<<"\n";
}
};
int main(){
	Sorts S;
	
	int y =1;
	while( y==1){
		cout<<"\n1.INSERTION SORT---";
	
	cout<<"\n2.BUBBLE SORT-";
	
	cout<<"\n3.SELECTION SORT--";
	cout<<"\n4.exit\n";
	int z;
	cin>>z;
	switch(z){
		case 1:
			S.insertion();
			break;
		case 2:
			S.bubble();
			break;
		case 3:
			S.selection();
			break;
		case 4:
			y=0;
			break;
		default:
			cout<<"select proper..\n";

	}
	}
}
