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

int findPosition(int arr[], int n, int element)
{
    for(int i = 0; i<n; i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}

Node* buildTreeFromPreorderInorder(int inOrder[], int preOrder[], int size, int &preIndex, int inStart, int inEnd)
{
    if(preIndex>=size || inStart>inEnd)
    {
        return NULL;
    }

    int element = preOrder[preIndex++];
    Node* root = new Node(element);

    int pos = findPosition(inOrder, size, element);
    root->left = buildTreeFromPreorderInorder(inOrder, preOrder, size, preIndex, inStart, pos-1);
    root->right = buildTreeFromPreorderInorder(inOrder, preOrder, size, preIndex, pos+1, inEnd);

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

    int inOrder[] = {40, 20, 50, 10, 60, 30, 70};
    int preOrder[] = {10, 20, 40, 50, 30, 60, 70};
    int size = 7;
    int preIndex = 0;
    int inStart = 0; 
    int inEnd = size-1;
    
    cout<<"build tree:"<<endl;
    Node* root = buildTreeFromPreorderInorder(inOrder, preOrder, size, preIndex, inStart, inEnd);
    cout <<"level order traversel" <<endl ;
    L_O_T(root);
    return 0;
}