#include <iostream>

using namespace std;

class node{
    public:
        int data;
        node *add;
        node *temp;
        node *New;
        node *prev;
        node *next;
        node *start=NULL;

    void create(){
        int n;
        char ch;
        cout<<"Enter a value: ";
        cin>>n;
        start=new node();
        start->data=n;
        start->add=NULL;
        
        temp=start;
        
        cout<<"To add more elments press 'y'"<<endl;
        cin>>ch;
        while(ch=='y' || ch=='Y'){
            cout<<"Enter next value: "<<endl;
            cin>>n;
            New=new node();
            New->data=n;
            New->add=NULL;
            temp->add=New;
            temp=New;
            cout<<"TO add more add more elements press 'y'"<<endl;
            cin>>ch;
        }
    }
    void insert(){
        int n, pos, count=0, i=1;
        if(start==NULL){
            cout<<"List not created"<<endl;
        }
        else{
            cout<<"Enter a value: "<<endl;
            cin>>n;
            New=new node();
            New->data=n;
            New->add=NULL;
            cout<<"Enter a position: "<<endl;
            cin>>pos;
            if(pos==1){
                New->add=start;
                start=New;
            }
            else{
                temp=start;
                while(temp!=NULL){
                    count++;
                    temp=temp->add;
                }
                if(pos>count+1){
                    cout<<"Invalid position it should be less than "<<count+1<<endl;
                }
                else if(pos==count+1){
                    temp=start;
                    while(temp->add!=NULL){
                        temp=temp->add;
                    }
                    temp->add=New;
                }
                else{
                    next=start;
                    while(i<pos){
                        prev=next;
                        next=next->add;
                        i++;
                    }
                    prev->add=New;
                    New->add=next;
                }
            }
        }
    }

    void Delete(){
        int pos, count=0, i=1;
        if(start==NULL){
            cout<<"List not created"<<endl;
        }
        else{
            cout<<"Enter position for delete: "<<endl;
            cin>>pos;
            if(pos==1){
                temp=start;
                start=start->add;
                cout<<"Deleted data: "<<temp->data<<endl;
                free(temp);
            }
            else{
                temp=start;
                while(temp!=NULL){
                    count++;
                    temp=temp->add;
                }
                if(pos>count){
                    cout<<"Invalid position, it should be less than or equal to "<<count<<endl;
                }
                else if(pos==count){
                    next=start;
                    while(next->add!=NULL){
                        prev=next;
                        next=next->add;
                    }
                    cout<<"Deleted data: "<<next->data<<endl;
                    free(next);
                    prev->add=NULL;
                }
                else{
                    next=start;
                    while(i<pos){
                        prev=next;
                        next=next->add;
                        i++;
                    }
                    temp=next;
                    cout<<"Deleted data: "<<temp->data<<endl;
                    next=next->add;
                    prev->add=next;
                }
            }
        }
    }

    void display(){
        if(start==NULL){
            cout<<"List not created, create a list first"<<endl;
        }
        else{
            temp=start;
            while(temp!=NULL){
                cout<<temp->data<<"  ";
                temp=temp->add;
            }
            cout<<endl;
        }
    }
};

int main()
{   
    node l1;
    int choice=0;
    
    do{
        cout<<"Press 1 for create"<<endl;
        cout<<"Press 2 for insert"<<endl;
        cout<<"Press 3 for delete"<<endl;
        cout<<"Press 4 for display"<<endl;
        cout<<"Press 5 for exit"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        
        switch(choice){
            case 1: l1.create(); break;
            case 2: l1.insert(); break;
            case 3: l1.Delete(); break;
            case 4: l1.display(); break;
            case 5: exit(0); break;
            default: cout<<"Enter valid choice!"<<endl;
        }
        
    }while(choice!=5);
    
    return 0;
}




