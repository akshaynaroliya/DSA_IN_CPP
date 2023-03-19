#include <iostream>
#include <queue>

using namespace std;

class node{
    public: 
        int data;
        node *left;
        node *right;
    node(){

    }

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

    void buildfromlevelorder(node * &root){
        queue <node *>q;
        cout<<"Enter data for root "<<endl;
        int data;
        cin>>data;
        root=new node(data);
        q.push(root);
        while (!q.empty())
        {
            node *temp=q.front();
            q.pop();
            cout<<"Enter left node for "<<temp->data<<endl;
            int leftData;
            cin>>leftData;
            if(leftData!=-1){
                temp->left=new node(leftData);
                q.push(temp->left);
            }
            cout<<"Enter right node for: "<<temp->data<<endl;
            int rightData;
            cin>>rightData;
            if(rightData!=-1){
                temp->right=new node(rightData);
                q.push(temp->right);
            }
        }
    }

    void inorder(node *root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
    }

    void preorder(node *root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<"  ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(node *root){
        if(root==NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"  ";
    }
};

int main(){
    
    node r;
    node *root=NULL;
    
    r.buildfromlevelorder(root);

    cout<<"After inorder: "<<endl;
    r.inorder(root);
    cout<<endl;
    cout<<"After preorder: "<<endl;
    r.preorder(root);
    cout<<endl;
    cout<<"After postorder: "<<endl;
    r.postorder(root);
    cout<<endl;

    return 0;
}
