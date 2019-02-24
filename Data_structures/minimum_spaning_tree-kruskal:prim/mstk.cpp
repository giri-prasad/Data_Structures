#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int arl[50],ars[50],arf[50];
class Mstk{
public:
   void bubble(int c){
	int i,j,x;
	for(i=1;i<=c;i++) {
		for(j=i+1;j<=c;j++) {
			if(arl[i]>arl[j]) {
			x=arl[i];
			arl[i]=arl[j];
			arl[j]=x;
			
			}
		}
	}
  }
  int find(int a){				//for finding the parent and returning the leader of given input..
  	int b;
  	b=arf[a];
  	while(1){
  		if(arf[b]==b){
  			return b;
  		}
  		else{
  			b=arf[b];
  		}
  	}
  }
  void unin(int x,int y){			//for union of two inputs.. if leders aren't same..
  	if(ars[x]>=ars[y]){
  		arf[y]=arf[x];
  		cout<<"\nedge added between---"<<x<<"--&--"<<y<<endl;
  		ars[x]=ars[x]+1;
  	}
  	else{
  		arf[x]=arf[y];
  		cout<<"\nedge added between---"<<y<<"--&--"<<x<<endl;
  		ars[y]=ars[y]+1;
  	}
  }
};
int main(){
	Mstk M;
	int a,b,c,z=1;
	cout<<"enter the number of vertices.....";
	cin>>a;				//a=number of vertices....
	cout<<"\nenter the number of edges(includes every edge...)..........";
	cin>>b;				//b=number of total edges....
	int arr[b][4];
	c=b;				//c=actual number of nodes excluding 1-1..and diff paths btw same nodes..... :)
	int d;
	cout<<"\nenter the vertex-1...vertex-2...and weight of edge..\n";
	for(d=1;d<=b;d++){		     				//for taking input in a 2D array... 
		cout<<"\nedge---"<<d<<"\n";
		int e,f,g;
		cin>>e;cin>>f;cin>>g;
		if(e!=f){
			if(z==1){
				arr[1][1]=e;
				arr[1][2]=f;
				arr[1][3]=g;
				z++;
			}
			else{
				int y=1,x=1;
				for(y=1;y<z;y++){
					if((arr[y][1]==e) && (arr[y][2]==f)){
						if(arr[y][3]>=g){
							arr[y][3]=g;
						}
							c--;
							x=0;
					}
				}
				if(x==1){
					arr[z][1]=e;
					arr[z][2]=f;
					arr[z][3]=g;
					z++;
				}
			}
		}
		else{
			c--;
		}
	}
	int h=1;
	for(h=1;h<=c;h++){
		arl[h]=arr[h][3];
	}
	for(h=1;h<=a;h++){
		arf[h]=h;
	}
	for(h=1;h<=a;h++){
		ars[h]=0;
	}
	M.bubble(c);
	int v=0;
	for(h=1;h<=c;h++){								//for finding minimum after sorting and doing
		int z=1,u=1;								//find and union....
		while(z==1){
			if(arr[u][3] == arl[h]){
				if(M.find(arr[u][1])!=M.find(arr[u][2])){
					M.unin(arr[u][1],arr[u][2]);
					v++;
					if(v==(a-1)){
						return 0;
					}
					z=0;	
				}
				else{
					u++;
					if(u>c)
					z=0;
				}
				
			}
			else{
				u++;
				if(u>c)
				z=0;
			}
			
		}
	}
}