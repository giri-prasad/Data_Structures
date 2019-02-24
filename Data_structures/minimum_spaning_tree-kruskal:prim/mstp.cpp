#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int arl[50],arv[50],arr[50][4],arp[50][4],p=1,q=1,r=1,vs=0,v=1,vv=1,a,c;  //r=main vertex. v r searching for adjacency..vs==visited array size..
class Mstp{													//q = for arp array
public:
	void bubble(int c){		//for sorting arl[]..
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
	void insertarp(int r){			//for having the adjacent nodes and having them in a new 2D array
		if(vs == a-1){				//and in recursively doing the prims algorithm/..without using heap..
			return;
		}							//if num of edges is (a-1) stop ....
		for(p=1;p<=c;p++){
			if(arr[p][1]==r || arr[p][2]==r){
				if(vs==0){
					arp[q][1]=arr[p][1];
					arp[q][2]=arr[p][2];
					arp[q][3]=arr[p][3];
					q++;
				}
				else{
					vv=1;
					for(v=1;v<=vs;v++){
						if(arr[p][1]==arv[v] || arr[p][2]==arv[v]){
							vv=0;
						}
					}
					if(vv==1){
						arp[q][1]=arr[p][1];
						arp[q][2]=arr[p][2];
						arp[q][3]=arr[p][3];
						q++;
					}
				}
			}
		}
		v=q-1;
		int va;
		for(va=1;va<=v;va++){
			arl[va]=arp[va][3];
		}
		bubble(v);
		int q=1,min;
		for(q=1;q<=v;q++){
			if(arl[q]!=0){
				min=arl[q];
				break;
			}
		}
		int a=1;
		for(a=1;a<=v;a++){					//finding the min from the sorted array....
			if(arp[a][3]==min)
				break;
		}
		int ab=0,ac=1;
		if(arp[a][1]==r)
			ab=1;
		if(arp[a][2]==r)
			ab=2;
		for(ac=1;ac<=vs;ac++){
			if(arp[a][1]==arv[ac])
				ab=1;
		}
		for(ac=1;ac<=vs;ac++){
			if(arp[a][2]==arv[ac])
				ab=2;
		}
		if(ab==1){						
			arv[vs+1]=r;
			vs++;
			int aa;
			aa=arp[a][2];
			cout<<"\nedge between--"<<arp[a][1]<<"--"<<arp[a][2]<<endl;
			arp[a][1]=0;
			arp[a][2]=0;
			arp[a][3]=0;
			insertarp(aa);
		}
		if(ab==2){
			arv[vs+1]=r;
			vs++;
			int aa;
			aa=arp[a][1];
			cout<<"\nedge between--"<<arp[a][1]<<"--"<<arp[a][2]<<endl;
			arp[a][1]=0;
			arp[a][2]=0;
			arp[a][3]=0;
			insertarp(aa);
		}
	}

};
int main(){
	Mstp M;
	int b,z=1;
	cout<<"enter the number of vertices.....";
	cin>>a;				//a=number of vertices....
	cout<<"\nenter the number of edges(includes every edge...)..........";
	cin>>b;				//b=number of total edges....
	c=b;				//c=actual number of nodes excluding 1-1..and diff paths btw same nodes..... :)
	int d;
	cout<<"\nenter the vertex-1...vertex-2...and weight of edge..\n";
	for(d=1;d<=b;d++){				//for taking input... and saving in 2D array....
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
	M.insertarp(r);
	
}