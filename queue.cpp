#include <iostream>

using namespace std;

#define MAX 10
int rear=-1, front=0, q[MAX];

void enqueue(){
    if(rear==MAX-1){
        cout<<"Stack overflow!"<<endl;
    }
    else{
        int n;
        cout<<"Enter element: "<<endl;
        cin>>n;
        rear++;
        q[rear]=n;
    }
}

void dequeue(){
    if(rear==-1 || front==rear+1){   //(front > rear)
        cout<<"Queue underflow!"<<endl;
    }
    else{
        cout<<"Deleted element is "<<q[front]<<endl;
        front++;
    }
}

void display(){
    if(rear==-1 || rear==front-1){    //(front > rear)
        cout<<"Queue empty!"<<endl;
    }
    else{
    for(int i=front; i<=rear; i++){
        cout<<q[i]<<"  ";
    }
    cout<<endl;
    }
}

int main(){
    
    int ch=0;
    
    do{
        cout<<"Press 1 for enqueue"<<endl;
        cout<<"Press 2 for dequeue"<<endl;
        cout<<"Press 3 for display"<<endl;
        cout<<"Press 4 for exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>ch;
        switch(ch){
            case 1: enqueue();  break;
            case 2: dequeue();  break;
            case 3: display();  break;
            case 4: exit(0);    break;
            default: cout<<"Please enter valid choice!"<<endl;   break;
        }
    }while(ch!=4);
    
    return 0;
}