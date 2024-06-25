#include<bits/stdc++.h>
using namespace std;

class Node{

  public: 

    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree()
{
    int data;
    cout<<"enter the data:" <<endl;
    cin>>data;
    if(data == -1)
    {
        return NULL;
    }

    Node* root = new Node(data);
    cout<<"enter data for left part of " <<data << " node "<<endl;
    root->left = buildTree();
    cout<<"enter data for right part of " <<data << " node "<<endl;
    root->right = buildTree();

    return root;
}

void preorder(Node* root)
{
   
    if(root==NULL)
    {
        return;
    }
    //NLR
    cout<<root->data<<" ";
    preorder(root->left);
    
    preorder(root->right);

}

int main()
{
   Node* root = NULL;
   root = buildTree();

   return 0;
}