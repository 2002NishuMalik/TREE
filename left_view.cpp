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

void leftView(Node* root, vector<int>& ans, int level)
{
    if(root == NULL)
    {
        return;
    }
    if(level == ans.size())
    {
        ans.push_back(root->data);
    }

    leftView(root->left, ans, level+1);
    leftView(root->right, ans, level+1);
}


int main()
{
   Node* root = NULL;
   root = buildTree();
   vector<int>ans;
   int level = 0;
   leftView(root, ans, level);
   return 0;
}