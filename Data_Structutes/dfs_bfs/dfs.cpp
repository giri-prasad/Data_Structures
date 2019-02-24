#include <iostream>
#include <sstream>
#include <string>
using namespace std;
struct node{
    int info;
    node *next;
};
int z;
int ar[50];
int a;
int arr[50][50];
node *head,*cur;
class Stack{
public:
    void push(int c){
            if(head==NULL){
                head=new node;
                cur=head;
                cur->info=c;
            }
            else{
                cur->next=new node;
                cur=cur->next;
                cur->info=c;
            }

    }
    void pop(){
        if(cur==head){
            head=NULL;
            delete cur;
        }
        else{
            node *temp;
            temp=head;
            while(temp->next!=cur){
                temp=temp->next;
            }
            cur=temp;
            temp=temp->next;
            cur->next=NULL;
            delete temp;
        }
    }
    int gettop(){
        
        return cur->info;
    }
    void dfs(int i){
        int v,b=1;
        for( b=1;b<=a;b++){
             v=1;
            if(arr[i][b]==1){
                for(int x=1;x<z;x++){
                    if(b==ar[x])
                         v=0;
                }
                if(v==1){
                    push(b);
                    ar[z]=b;
                    z++;
                    dfs(b);
                    return;
                }
            }
        }
        if(b>a){
            pop();
            if(head==NULL){
                return;
            }
            int e=gettop();
            dfs(e);
        }

    }
};
int main(){
    Stack S;
    cout<<"enter the num of vertex...\n";
    cin>>a;
    z=1;
    
    for(int i=1;i<=a;i++){
        cout<<"enter the elements of adjacency matrix..row"<<i<<endl;
        for(int j=1;j<=a;j++){
            cin>>arr[i][j];
        }
    }
    S.push(1);
    int d=S.gettop();
    //
    //cout<<d<<endl;  working..
    ar[z]=d;z++;
    //cout<<ar[1]<<endl;
    S.dfs(d);
    for(int f=1;f<=z;f++){
        cout<<ar[f]<<endl;
    }
}