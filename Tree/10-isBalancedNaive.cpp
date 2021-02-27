#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;

//check for balanced binary tree
//Time complexity : O(n*n)
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

ll height(node* root)
{
    if(root==NULL)return 0;
    return 1+max(height(root->left),height(root->right));
}

bool isBalanced(node* root)
{
    if(root==NULL)return true;
    ll lh=height(root->left);
    ll rh=height(root->right);
    return (abs(lh-rh)<=1)&&(isBalanced(root->left))&&(isBalanced(root->right));
}

int main()
{
    node* root=new node(20);
    root->left=new node(5);
    root->right=new node(15);
    root->left->left=new node(3);
    root->left->right=new node(2);
    
    if(isBalanced(root))cout<<"YES";
    else cout<<"NO";
    
    
}