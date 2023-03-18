#include <iostream>

using namespace std;

#define MAX 10
int topA=-1, topB=MAX, stack[MAX];

void pushA(){
    if(topA==topB-1){
        cout<<"Multiple stack overflow!"<<endl;
    }
    else{
        int n;
        cout<<"Enter element: ";
        cin>>n;
        topA++;
        stack[topA]=n;
    }
}

void pushB(){
    if(topB==topA+1){
        cout<<"Multiple stack overflow!"<<endl;
    }
    else{
        int n;
        cout<<"Enter element: ";
        cin>>n;
        topB--;
        stack[topB]=n;
    }
}

void popA(){
    if(topA==-1){
        cout<<"StackA underflow!"<<endl;
    }
    else{
        cout<<"Deleted element is "<<stack[topA]<<endl;
        topA--;
    }
}

void popB(){
    if(topB==MAX){
        cout<<"stackB underflow!"<<endl;
    }
    else{
        cout<<"Deleted element is "<<stack[topB]<<endl;
        topB++;
    }
}

void displayA(){
    if(topA==-1){
        cout<<"StackA empty!"<<endl;
    }
    else{
    for(int i=0; i<=topA; i++){
        cout<<stack[i]<<"  ";
    }
    cout<<endl;
    }
}
void displayB(){
    if(topB==MAX){
        cout<<"StackB empty!"<<endl;
    }
    else{
    for(int i=MAX-1; i>=topB; i--){
        cout<<stack[i]<<"  ";
    }
    cout<<endl;
    }
}
void display(){
    if(topA==-1 && topB==MAX){
        cout<<"Stack empty!"<<endl;
    }
    else{
        for(int i=0; i<=topB; i++){
            cout<<stack[i]<<"  "; 
        }
        cout<<endl;
    }
}

int main(){
    int ch=0;
    do{
        cout<<"Enter your choice: "<<endl;
        cout<<"Press 1 for push in stack A"<<endl;
        cout<<"Press 2 for pop in stack A"<<endl;
        cout<<"Press 3 for display stack A"<<endl;
        cout<<"Press 4 for push in stack B"<<endl;
        cout<<"Press 5 for pop in stack B"<<endl;
        cout<<"Press 6 for display stack B"<<endl;
        cout<<"Press 7 for display all elements present in the both the stack"<<endl;
        cout<<"Press 8 for exit"<<endl;
        cin>>ch;
        switch(ch){
            case 1: pushA(); break;
            case 2: popA(); break;
            case 3: displayA(); break;
            case 4: pushB(); break;
            case 5: popB(); break;
            case 6: displayB(); break;
            case 7: display(); break;
            case 8: exit(0); break;
            default: cout<<"Please enter valid choice!"<<endl; break;
        }
    }while(ch);
    
    return 0;
}