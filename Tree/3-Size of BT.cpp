#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;

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

ll sizeoftree(node* root)
{
    if(root==NULL)return 0;
    return 1+sizeoftree(root->left)+sizeoftree(root->right);
}

int main()
{
    node* root=new node(10);
    root->left=new node(5);
    root->right=new node(20);
    root->left->left=new node(25);
    
    cout<<sizeoftree(root);
    
}