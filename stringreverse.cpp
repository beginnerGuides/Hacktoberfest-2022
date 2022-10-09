#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    struct node *next;
}node;
struct node *top=NULL;

void push(char s){
    if (top==NULL){
        struct node *p=new struct node;
        p->data=s;
        p->next=NULL;
        top=p;
    }
    else{
        struct node *p=new struct node;
        p->data=s;
        p->next=top;
        top=p;
    }
}
void display(){
     if(top==NULL){
        cout<<"underflow"<<endl;
    }
    else{
        struct node *q=top;
        while(q!=NULL){
            cout<<q->data;
            q=q->next;
        }
    }
}
int main(){
    string s;
    getline(cin,s);
    int k = 0;
    while (s[k])
     k++;
    for(int i=0;i<k;i++)
     push(s[i]);
    display();
    return 0;
}
