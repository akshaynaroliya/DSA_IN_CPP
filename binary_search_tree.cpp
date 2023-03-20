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

Node *minVal(Node *root){
    Node *temp=root;
    while(temp->left != NULL){
        temp=temp->left;
    }

    return temp;
}

Node *deleteFromBST(Node *root, int val){
    if(root == NULL){
        return root;
    }
    if(root->data==val){
        if(root->left == NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left!=NULL && root->right==NULL){
            Node *temp=root->left;
            delete root;
            return temp;
        }
        if(root->right==NULL && root->right!=NULL){
            Node *temp=root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL && root->right!=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right=deleteFromBST(root->right, val);
        return root;
    }
    return root;  //not necessary, written for warning
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

int main(){

    Node *root=NULL;

    takeInput(root);

    levelOrderTraversal(root);

    deleteFromBST(root, 40);

    cout<<"After deletion: "<<endl;

    levelOrderTraversal(root);

    return 0;
}



