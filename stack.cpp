#include <iostream>

using namespace std;

#define MAX 10
int top=-1, stack[MAX];

void push(){
    if(top==MAX-1){
        cout<<"Stack overflow"<<endl;
    }
    else{
        top++;
        int n;
        cout<<"Enter element: "<<endl;
        cin>>n;
        stack[top]=n;
    }
}

void pop(){
    if(top==-1){
        cout<<"Stack underflow"<<endl;
    }
    else{
        cout<<"Deleted element is "<<stack[top]<<endl;
        top--;
    }
}

void display(){
    if(top==-1){
        cout<<"Stack empty"<<endl;
    }
    else{
        cout<<"Stack element"<<endl;
        for(int i=0; i<=top; i++){
            cout<<stack[i]<<"  ";
        }
        cout<<endl;
    }
}

int main(){
    int ch=0;
    do{
        cout<<"Enter your choice: "<<endl;
        cout<<"Press 1 for push"<<endl;
        cout<<"Press 2 for pop"<<endl;
        cout<<"Press 3 for display"<<endl;
        cout<<"Press 4 for exit"<<endl;
        cin>>ch;
        switch(ch){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0); break;
            default: cout<<"Enter valid choice"<<endl; break;
        }
    }while(ch);
    
    return 0;
}

