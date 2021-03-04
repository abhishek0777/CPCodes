/*
A very good examply
        20
      /    \
     8     30
         /    \
        18   35
This is not a BST

A wrong solution:
Do any traversal,for every node check if its left child is smaller and right is greater 

A correct but inefficient
a. Find maximum in left subtree
b. find minumum if right subtree
c. Check if the current node is greater than the maximum and smaller than the minimum

An efficient:
=> Pass a range for every node
=> For root,range is -inf to +inf
=> For left child of a node,in range,we change upper bound as the node's value
=> For right child of a node,in range,we change lower bound as the node's value

Inorder Traversal
=>Maintain prev variable
=>every node value have value greater than prev
*/ 
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


bool checkBST(node* root,int min,int max)
{
    if(root==NULL)return true;
    return (root->key>min)&&
           (root->key<max)&&
           checkBST(root->left,min,root->key)&&
           checkBST(root->right,root->key,max);
}

//inorder traversal
int prev=INT_MIN;
bool isBST(Node* root)
{
    if(root==NULL)return true;
    if(isBST(root->left)==false)return false;
    if(root->key<=prev)return false;
    prev=root->key;
    return isBST(root->right);
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
    
    if(checkBST(root,INT_MIN,INT_MAX))cout<<"YES\n";
    else cout<<"NO\n";
}