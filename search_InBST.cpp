#include <iostream>
#include <queue> 

using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }
};

Node *insertNode(Node *root, int d){
    if(root == NULL){
        root=new Node(d);
        return root;
    }
    if(d > root->data){
        root->right=insertNode(root->right, d);
    }
    else{
        root->left=insertNode(root->left, d);
    }

    return root;
}

void takeInput(Node * &root){
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;
    while (data!=-1){
        root=insertNode(root, data);
        cin>>data;
    }
}

void levelOrderTraversal(Node *root){
        queue <Node *> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node *temp=q.front();
            q.pop();
            if(temp==NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                cout<<temp->data<<"  ";  
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
}

//recursive way
void searchInBST(Node *root, int x){
    if(root==NULL){
        cout<<"Tree does not contain "<<x<<" element"<<endl;
        return;
    }
    if(root->data==x){
        cout<<"Tree contain "<<x<<" element"<<endl;
        return;
    }
    if(root->data > x){
        searchInBST(root->left, x);
    }
    else{
        searchInBST(root->right, x);
    }
}

//Iterative way
void sInBST(Node *root, int x){
    Node *temp=root;
    while(temp!=NULL){
        if(temp->data==x){
            cout<<x<<" found"<<endl;
            return;
        }
        if(temp->data > x){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    cout<<x<<" not found"<<endl;
    return;
}

int main(){

    Node *root=NULL;

    takeInput(root);

    levelOrderTraversal(root);

    searchInBST(root, 6);
    
    sInBST(root, 6);

    return 0;
}



