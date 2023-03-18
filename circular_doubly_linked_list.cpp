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
    int n, count=0, pos, i;
    char ch;
    
    void create(){
        if(start!=NULL){
            cout<<"You cant create list, list already created!"<<endl;
        }
        else{
            cout<<"Enter value: "<<endl;
            cin>>n;
            start=new node();
            start->data=n;
            start->ladd=start;
            start->radd=start;
            count++;
            cout<<"If want to add more elments, press 'y'"<<endl;
            cin>>ch;
            temp=start;
            while(ch=='y' || ch=='Y'){
                cout<<"Enter value: "<<endl;
                cin>>n;
                New=new node();
                New->data=n;
                New->ladd=temp;
                temp->radd=New;
                New->radd=start;
                start->ladd=New;
                temp=New;
                count++;
                cout<<"If you want to add more elments, press 'y'"<<endl;
                cin>>ch;
            }
        }
    }
    
    void insert(){
        if(start==NULL){
            cout<<"List not created!"<<endl;
        }
        else{
            cout<<"Enter value: "<<endl;
            cin>>n;
            cout<<"Enter position: "<<endl;
            cin>>pos;
            if(pos>count+1){
                cout<<"You cant insert element position should be less than or equall to "<<count+1<<endl;
            }
            else{
                temp=start;
                New=new node();
                New->data=n;
                if(pos==1){
                    start->ladd->radd=New;
                    New->ladd=start->ladd;
                    New->radd=start;
                    start->ladd=New;
                    start=New;
                    count++;
                }
                else if(pos==count+1){
                    start->ladd->radd=New;
                    New->ladd=start->ladd;
                    New->radd=start;
                    start->ladd=New;
                    count++;
                }
                else{
                    i=2;
                    while(i<pos){
                        temp=temp->radd;
                        i++;
                    }
                    temp->radd->ladd=New;
                    New->radd=temp->radd;
                    temp->radd=New;
                    New->ladd=temp;
                    count++;
                }
            }
        }
    }
    
    void Delete(){
        if(start==NULL){
            cout<<"List not created, create a list first"<<endl;
        }
        else{
            cout<<"Enter position for delete: "<<endl;
            cin>>pos;
            if(pos>count){
                cout<<"You cant insert element, position should be less than or equal to "<<count<<endl;
            }
            if(pos==1 && start->radd==start){
                cout<<"Deleted data: "<<start->data<<endl;
                start=NULL;
                count--;
            }
            else if(pos==1){
                temp=start;
                start=start->radd;
                start->ladd=temp->ladd;
                count--;
            }
            else if(pos==count){
                temp=start;
                cout<<"Deleted data: "<<temp->ladd->data<<endl;
                start->ladd=temp->ladd;
                temp->ladd->ladd->radd=start;
                count--;
            }
            else{
                temp=start;
                i=1;
                while(i<pos){
                    temp=temp->radd;
                    i++;
                }
                cout<<"Deleted data: "<<temp->data<<endl;
                temp->ladd->radd=temp->radd;
                temp->radd->ladd=temp->ladd;
                delete temp;
                count--;
            }
        }
    }
    
    void display(){
        if(start==NULL){
            cout<<"List not created!!!!!"<<endl;
        }
        else{
            temp=start;
            do{
                cout<<temp->data<<"  ";
                temp=temp->radd;
            }while(temp!=start);
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










