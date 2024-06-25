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

void L_O_T(Node *root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp==NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout <<temp->data <<" ";
            if(temp->left)
            {
               q.push(temp->left);
            }
            if(temp->right)
            {
               q.push(temp->right);
            } 

        }
        
    }
}

int main()
{
   Node* root = NULL;
   
   root = buildTree();

   L_O_T(root);

   return 0;
}