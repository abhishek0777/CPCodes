#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define NIL INT_MIN
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

vector<int> in; 
void inorder(node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

//fix a BST with two nodes swapped
node *prv=NULL,*first=NULL,*second=NULL;
void fixBST(node* root)
{
    if(root==NULL)return;
    fixBST(root->left);
    if(prv!=NULL&&root->key<prv->key)
    {
        if(first==NULL)first=prv;
        second=root;
    }
    prv=root;
    fixBST(root->right);
}

int main()
{
    node* root=newNode(20);
    root->left=newNode(60);
    root->left->left=newNode(4);
    root->left->right=newNode(10);
    root->right=newNode(80);
    root->right->left=newNode(8);
    root->right->right=newNode(100);
    
    // in this 60 and 8 are implaced,we have to swap them
    fixBST(root);
    cout<<first->key<<" "<<second->key;
    
}