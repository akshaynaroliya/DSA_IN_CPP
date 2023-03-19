#include <iostream>

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

    node *buildTree(node *root){
        cout<<"Enter the data: "<<endl;
        int data;
        cin>>data;
        root=new node(data);
        if(data==-1){
            return NULL;
        }
        cout<<"Enter data for inserting in left of "<<data<<endl;
        root->left=buildTree(root->left);
        cout<<"Enter data for inserting in right of "<<data<<endl;
        root->right=buildTree(root->right);
    
        return root;
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
    root=r.buildTree(root);

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
