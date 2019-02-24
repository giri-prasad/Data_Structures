
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int array[20];       

class Merge{
public:
  int segrigate(int array[],int low,int high);
private:
  void clubtogether(int array[],int minele,int maxele);

};



int main(){
  Merge M;
  int n,i;
  cout<<"Enter the size of arrayay\n";
  cin>>n;
  cout<<"Enter the numbers\n";
  for(i=0;i<n;i++)
    cin>>array[i];
  cout<<"given input is\n";
  for(i=0;i<n;i++)
    cout<<array[i]<<"  ";

  M.segrigate(array,0,n-1);  
printf("\nSorted arrayay:\n");  
for(i=0; i<n; i++)
printf("%d \n",array[i]);
return 0;

}
void Merge::clubtogether(int array[],int minele,int maxele)
{
  int midele;
  midele=(minele+maxele)/2;
  int temp[30];
  int i,j,k,m; 
  j=minele;
  m=midele+1;
  for(i=minele; j<=midele && m<=maxele ; i++)
  {
     if(array[j]<=array[m])
     {
         temp[i]=array[j];
         j++;
     }
     else
     {
         temp[i]=array[m];
         m++;
     }
  }
  if(j>midele)
  {
     for(k=m; k<=maxele; k++)
     {
         temp[i]=array[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=midele; k++)
     {
        temp[i]=array[k];
        i++;
     }
  }
  for(k=minele; k<=maxele; k++)
     array[k]=temp[k];
}



int Merge::segrigate(int array[],int low,int high)
{
int midele;
if(low<high) {
    midele=(low+high)/2;

segrigate(array,low,midele);
segrigate(array,midele+1,high);
clubtogether(array,low,high);
  }
return 0;
}
