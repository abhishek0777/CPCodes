#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;

// Time complexity : O(n)
// Auxiliary space : O(h)

struct node{
    ll key;
    node* left;
    node* right;
    node(ll k)
    {
        key=k;
        left=right=NULL;
    }
};

void inorder(node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void preorder(node* root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}

int main()
{
    node* root=new node(10);
    root->left=new node(5);
    root->right=new node(20);
    root->left->left=new node(25);
    cout<<"Inorder : ";
    inorder(root);
    cout<<endl;
    
    cout<<"Preorder : ";
    preorder(root);
    cout<<endl;
    
    cout<<"Post order : ";
    postorder(root);
    
}