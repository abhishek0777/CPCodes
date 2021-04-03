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

void mxBT(node* root)
{
    if(root==NULL)return INT_MIN;
    return max(root->key,max(mxBT(root->left),mxBT(root->right)));
}



int main()
{
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    
    cout<<maxBT(root);
    
}