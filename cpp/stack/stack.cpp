// with class in c++
#include<iostream>
#define SIZE 10
using namespace std;
// define a class 
class Stack{
    int top;
public:
  char character[SIZE]; // stack array for character
 Stack(){
     top = -1;
 }
 // checking for is the stack is full
//  bool isFull(){
//      if(top == SIZE) return true;
//      else return false;
//  }
//  // checking for is the stack is empty
//  bool isEmpty(){
//      if(top == -1) return true;
//      else return false;
//  }
 // adding a element into stack array
 void push(char item)
 {
     if(top == SIZE-1){
        printf("overflow the stack you cannot add element\n");
     }
     else
     {
          top++;
         character[top] = item;
     }
 }
 char pop()
 {
     if(top == -1)
     {
          printf("the stack is underflow you cannot remove anything");
       } 
     else
     {
         top--;
         char popedItem = character[top];
         return popedItem;
     }
 }
 void display(){
    if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<character[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
 }
};
int main()
{
  Stack s;
  s.push('A');
  s.push('B');
   s.push('C');
    s.push('D');
  s.display();
  s.pop();
  s.display();
  
}