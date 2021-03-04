#include<bits/stdc++.h>
#define ll long long int
using namespace std;
struct node{
  ll key;
  node* left;
  node* right;
  node(ll k)
  {
      key=k;
      left=NULL;
      right=NULL;
  }
  
};

node* getSuccessor(node* curr)
{
    curr=curr->right;
    while(curr!=NULL&&curr->left!=NULL)curr=curr->left;
    return curr;
}

//Delete has three cases:
node* delNode(node* root,ll x)
{
    if(root==NULL)return root;
    if(root->key>x)root->left=delNode(root->left,x);
    else if(root->key<x)root->right=delNode(root->right,x);
    else 
    {
        if(root->left==NULL)
        {
            node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node* temp=root->left;
            free(root);
            return temp;
        }
        else
        {
            node* succ=getSuccessor(root);
            root->key=succ->key;
            root->right=delNode(root->right,succ->key);
            return root;
        }
        
    }
}


int main()
{
    node *root=new node(15);
    root->left=new node(5);
    root->left->left=new node(3);
    root->right=new node(20);
    root->right->right=new node(80);
    root->right->left=new node(18);
    root->right->left->left=new node(16);
    
    root=delNode(root,80);
    
}