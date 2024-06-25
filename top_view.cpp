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

void topView(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    map<int, int> topnode;
    queue<pair<Node*, int>>q;
    q.push({root, 0});

    while(!q.empty())
    {
        pair<Node*, int>temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        if(topnode.find(hd) == topnode.end())
        {
            topnode[hd] =  frontNode->data;
        }

        if(frontNode->left)
        {
            q.push({frontNode->left, hd-1});
        }
        if(frontNode->right)
        {
            q.push({frontNode->right, hd+1});
        }
    }
    cout<<"printing the top view: "<<endl;
    for(auto i : topnode)
    {
        cout<< i.first <<"-> "<<i.second<<endl;
    }
}


int main()
{
    Node* root = root = buildTree();
    topView(root);
    return 0;
}