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

//recursive
node* insert(node* root,ll x)
{
    if(root==NULL)return new node(x);
    else if(root->key<x)root->right=insert(root->right,x);
    else if(root->key>x)root->left=insert(root->left,x);
    return root;
}

//iterative
node* insert(node* root,ll x)
{
    node* parent=NULL;
    node* curr=root;
    node* temp=new node(x);
    while(curr!=NULL)
    {
        parent=curr;
        if(curr->key<x)curr=curr->left;
        else if(curr->key>x)curr=curr->right;
        else return root;
    }
    //when given tree is empty
    if(parent==NULL)return temp;
    
    if(parent->key>x)parent->left=temp;
    else parent->right=temp;
    
    return root;
}
int main()
{
    node* root=new node(15);
    root->left=new node(5);
    root->left->left=new node(3);
    root->right=new node(20);
    root->right->right=new node(80);
    root->right->left=new node(18);
    root->right->left->left=new node(16);
    
    root=insert(root,17);
}