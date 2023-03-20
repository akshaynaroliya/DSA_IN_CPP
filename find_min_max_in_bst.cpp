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

Node *minVal(Node *root){
    Node *temp=root;
    while(temp->left != NULL){
        temp=temp->left;
    }

    return temp;
}

Node *maxVal(Node *root){
    Node *temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }

    return temp;
}

int main(){

    Node *root=NULL;

    takeInput(root);

    levelOrderTraversal(root);

    cout<<"Minimum value: "<<minVal(root)->data;

    cout<<endl;

    cout<<"Maximum value: "<<maxVal(root)->data;

    return 0;
}



