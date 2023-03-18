#include<iostream>
using namespace std;

class node{
    public: 
    int data;
    node *start=NULL;
    node *ladd;
    node *radd;
    node *New;
    node *temp;
    int n, count=0, pos;
    char ch;
    void create(){
        if(start!=NULL){
            cout<<"List already created, you cant create list!"<<endl;
        }
        else{
            cout<<"Enter value: "<<endl;
            cin>>n;
            start=new node();
            start->data=n;
            start->ladd=NULL;
            start->radd=NULL;
            temp=start;
            count++;
            
            cout<<"If you want to insert more elements press 'y'"<<endl;
            cin>>ch;
            
            while(ch=='y' || ch=='Y'){
                cout<<"Enter value: "<<endl;
                cin>>n;
                New=new node();
                New->data=n;
                New->ladd=temp;
                New->radd=NULL;
                temp->radd=New;
                temp=New;
                count++;
                cout<<"If you want to insert more elements press 'y'"<<endl;
                cin>>ch;
            }
        }
    }
    
    void insert(){
        if(start==NULL){
            cout<<"List not created, create a list first!"<<endl;
        }
        else{
            cout<<"Enter value: "<<endl;
            cin>>n;
            New=new node();
            New->ladd=NULL;
            New->radd=NULL;
            New->data=n;
            cout<<"Enter postion for insert: "<<endl;
            cin>>pos;
            if(pos==1){
                New->radd=start;
                start->ladd=New;
                start=New;
                count++;
            }
            else if(pos==count+1){
                temp=start;
                while(temp->radd!=NULL){
                    temp=temp->radd;
                }
                temp->radd=New;
                New->ladd=temp;
                count++;
            }
            else{
                temp=start;
                int i=2;
                while(i<pos){
                    temp=temp->radd;
                    i++;
                }
                New->radd=temp->radd;
                temp->radd->ladd=New;
                New->ladd=temp;
                temp->radd=New;
                count++;
            }
        }
    }
    
    void Delete(){
        if(start==NULL){
            cout<<"List not created, create a list first!"<<endl;
        }
        else{
            cout<<"Enter position for delete: ";
            cin>>pos;
            if(pos>count){
                cout<<"Position should be less than or equal to "<<count<<endl;
            }
            else if(pos==1 && start->radd==NULL){
                cout<<"Deleted element: "<<start->data<<endl;
                start=NULL;
                count--;
            }
            else if(pos==1){
                cout<<"Deleted element: "<<start->data<<endl;
                start=start->radd;
                start->ladd=NULL;
                count--;
            }
            else if(pos==count){
                temp=start;
                while(temp->radd!=NULL){
                    temp=temp->radd;
                }
                cout<<"Deleted data: "<<temp->data<<endl;
                temp->ladd->radd=NULL;
                count--;
                delete temp;
            }
            else{
                temp=start;
                int i=1;
                while(i<pos){
                    temp=temp->radd;
                    i++;
                }
                cout<<"Delted data: "<<temp->data<<endl; 
                temp->ladd->radd=temp->radd; 
                count--;
                delete temp;
            }
        }
    }
    
    void display(){
        if(start==NULL){
            cout<<"List not created!!!!!"<<endl;
        }
        else{
            temp=start;
            while(temp!=NULL){
                cout<<temp->data<<"  ";
                temp=temp->radd;
            }
            cout<<endl;
        }
    }
};

int main(){
    node d;
    int ch;
    do{
        cout<<"Press 1 for create."<<endl;
        cout<<"Press 2 for insert."<<endl;
        cout<<"Press 3 for delete."<<endl;
        cout<<"Press 4 for display."<<endl;
        cout<<"Press 5 for exit."<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch (ch)
        {
            case 1: 
                d.create(); break;
            case 2:
                d.insert(); break;
            case 3:
                d.Delete(); break;
            case 4:
                d.display(); break;
            case 5:
                break;
            default: cout<<"Please enter valid choice!"<<endl;
            break;
        }
    }while(ch!=5);
    return 0;
}