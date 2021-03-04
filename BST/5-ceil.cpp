#include<bits/stdc++.h>
#define ll long long int
using namespace std;
struct node{
  int key;
  struct node *left,*right;
  
};

node* newNode(int k)
{
    node* temp = new node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

//recursivve insertion 
node* insert(node* root,int x)
{
    if(root==NULL)return newNode(x);
    else if(root->key<x)root->right=insert(root->right,x);
    else if(root->key>x)root->left=insert(root->left,x);
    return root;
}



void inorder(node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

node* ceilV(node* root,int x)
{
    node* ans=NULL;
    while(root!=NULL)
    {
        if(root->key==x)return root;
        else if(root->key<x)
        {
            root=root->right;
        }
        else 
        {
            ans=root;
            root=root->left;
        }
    }
    return ans;
}

int main()
{
    node* root=NULL;
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,70);
    root=insert(root,60);
    root=insert(root,80);
    
    // inorder(root);
    if(floorV(root,55))
    cout<<ceilV(root,55)->key;
    else cout<<"No ceil value"
}