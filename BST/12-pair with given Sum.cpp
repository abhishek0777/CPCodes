/*
Pair with given sum in BST
Method-1:
1. Do an inorder traversal of the given BST and store it in an array.
2. Use two pointer approach to find if array has a pair with given sum. 

Method-2:
Hashing
1. store every node u visited ,then for every node chck sum-key is present in map or not.

Method-3:

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

unordered_set<int> s;
bool isPairSum(node* root,int sum)
{
    if(root==NULL)return false;
    if(isPairSum(root->left,sum))return true;
    if(s.find(sum-root->key)!=s.end())return true;
    else s.insert(root->key);
    return isPairSum(root->right,sum);
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
    
    if(isPairSum(root,40))cout<<"Present\n";
    else cout<<"not present\n";
    
    if(isPairSum(root,110))cout<<"Present\n";
    else cout<<"not present\n";
}