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
class Queu{
public:
    void insert(int c){
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
    void del(){
        if(cur==head){
            head=NULL;
            delete cur;
        }
        else{
            node *temp;
            temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }
    int gethead(){
        
        return head->info;
    }
    void bfs(int i){
        int v,b=1;
        for( b=1;b<=a;b++){
             v=1;
            if(arr[i][b]==1){
                for(int x=1;x<z;x++){
                    if(b==ar[x])
                         v=0;
                }
                if(v==1){
                    insert(b);
                    ar[z]=b;
                    z++;
                    
                }
            }
        }
        if(b>a){
            del();
            if(head==NULL){
                return;
            }
            int e=gethead();
            bfs(e);
        }

    }
};
int main(){
    Queu S;
    cout<<"enter the num of vertex...\n";
    cin>>a;
    z=1;
    
    for(int i=1;i<=a;i++){
        cout<<"enter the elements of adjacency matrix..row"<<i<<endl;
        for(int j=1;j<=a;j++){
            cin>>arr[i][j];
        }
    }
    S.insert(1);
    int d=S.gethead();
    //
    //cout<<d<<endl;  working..
    ar[z]=d;z++;
    //cout<<ar[1]<<endl;
    S.bfs(d);
    for(int f=1;f<=z;f++){
        cout<<ar[f]<<endl;
    }
}