/*
//assignment submission 7
//minimum flow of graph...
//prof..shoban babu..
//ta .. shalini jain..
//student name A.giir  prasad..
//es14btech11002.....
//compiled  on mac terminal....
*/
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;
int n;  					//no of vertices declared as global varaiable
int Arr[50][50];
int parent[50];
class mflow{
public:
	mflow(){
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)    //input  directed graph
			{
				Arr[i][j]=0;  //initializing the weight of the array as 0
			}
		}
	}
	int route( int Arr[50][50], int a,int b)///////
	{
	    int i,j;
	    bool verify[n-1];   //verify if  the vertex is visited or not
	    for(i=0;i<n;i++)
	       verify[i]=false;
	    queue<int> objq;
	    objq.push(a);        //pushing the first vertex into the queue
	    parent[a]=-1;     
	    verify[a]=true;  //the source's parent NULL changing the source as visited
	    while(!objq.empty())
	    {
	    	i=objq.front();
	    	objq.pop();
	    	j=0;
	         	while(j<n)
	        	{
	    	    	if(verify[j]==false&&Arr[i][j]>0)   //if the edge has weight
	    	    	{
	    	    		verify[j]=true;  //changing it as visited
	    	    		parent[j]=i;   //changing the parent of next vetrex to the previuos vertes such that we can trace the route
	    	    		objq.push(j);     // pushing into the queue
					}
					j++;
			   }
		}
		if(verify[b]==true)  //if end point is visited then we have found the route
		 return true;
		else
		  return false;		  
	}
int maxflow(int a,int b)
{
	int clone[50][50];  //copying the value of array so that the changes doesn't effect main input..
	int i,j;
	int minimum;
	int maximum=0;  //the flow of the network intialized as 0..
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			clone[i][j]=Arr[i][j];
		}
	}
	while(route(clone,a,b)==true)  //if we found a route..  ////// 
	{
		 int x=1;
		 int p;	//we have to come from the end point using parent by tracing the route  untill we get to starting point
		for(i=b;i!=a;i=parent[i] )
		{	
			p=parent[i];  //we are finding  i's parent...
			if(x==1)
			{
				minimum=clone[p][i];
				x++;	
			}
			else
			{
				if(minimum>clone[p][i])   
				  minimum=clone[p][i];
			} //moving i to its parent for retracing its parent			
		}     //now we have found the minimum value in the route we have to modify the copy values
		for(i=b;i!=a;i=parent[i])
		{ 
		    p=parent[i];
		    clone[p][i]=clone[p][i]-(minimum);   //decreasing the forward weight of the flow
		    clone[i][p]=clone[i][p]+(minimum);   //adding the min if the edge has backward flow
    	}  			
	    maximum=maximum+(minimum);
	}		//if there are no mpore paths ,the while loop will terminate...
	cout<<"\n max flow in the given graph from staring point  to ending point .....";
	cout<<maximum<<endl;
	return 0;
}
};
int main()
{
	mflow M;
	int i,j,e,p,q,w,start,end;
	cout<<"\n no of vertices in the graph..";
	cin>>n;
	cout<<"\n no of edges in the graph...";
	cin>>e;
	cout<<"\nhere the vertices start from 0 so take care while entering the input..\n";
	cout<<"\n starting and ending and edge weight accordingly..\n";
	for( i=0;i<e;i++)
	{
		cout<<"\nenter edge..."<<i+1<<"....";
		cin>>p;
		cin>>q;
		cin>>w;
		Arr[p][q]=w;  //taking the input weight of the vertex
	}
	cout<<"\nenter the staring point i:e source... ";
	cin>>start;
	cout<<"\nenter the end point i:e destination...";
	cin>>end;
	M.maxflow(start,end);
}