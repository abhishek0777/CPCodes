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


//Delete has three cases:
node* delNode(node* root,int x)
{
    if(root==NULL)return root;
    if(root->key>x)root->left=delNode(root->left,x);
    else if(root->key<x)root->right=delNode(root->right,x);
    else 
    {
        if(root->left==NULL)
        {
            node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            node* temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            node* succP=root;
            node* succ=root->right;
            while(succ->left!=NULL)
            {
                succP=succ;
                succ=succ->left;
            }
            if(succP!=root)succP->left=succ->right;
            else succP->right=succ->right;
            root->key=succ->key;
            delete succ;
        }
        
    }
    
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
    
    inorder(root);
    cout<<endl;
    root=delNode(root,80);
    inorder(root);
}