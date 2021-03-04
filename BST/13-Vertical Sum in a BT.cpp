/*
Vertical sum in a binary tree
            10
          /    \
        15     25
       /   \
      35    20
     /       \
    40       75
               \
               80

 O/p: 40 35 15 30 100 80   

 Bonus ques: print vertical traversal of tree in order from top to bottom           
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

map<ll,ll> mpp;
void verticalSum(node* root,int hd)
{
    if(root==NULL)return;
    verticalSum(root->left,hd-1);
    mpp[hd]+=root->key;
    verticalSum(root->right,hd+1);
}

// Time complexity: O(nlog(hd)+hd)

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
    
    verticalSum(root,0);
    for(auto p:mpp)cout<<p.first<<" "<<p.second<<endl;
}