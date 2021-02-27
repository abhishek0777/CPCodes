#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;

//check for balanced binary tree(efficient)
//Time complexity : O(n)
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

//return 0/1 if balanced ,-1 if unbalanced

ll isBalanced(node* root)
{
    if(root==NULL)return 0;
    ll lh=isBalanced(root->left);
    if(lh==-1)return -1;
    ll rh=isBalanced(root->right);
    if(rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;
    else return (max(lh,rh)+1);
}

int main()
{
    node* root=new node(20);
    root->left=new node(5);
    root->right=new node(15);
    root->left->left=new node(3);
    root->left->right=new node(2);
    
    if(isBalanced(root)!=-1)cout<<"YES";
    else cout<<"NO";
    cout<<endl;
    root=new node(8);
    root->left=new node(12);
    root->left->left=new node(13);
    root->left->right=new node(14);
    root->right=new node(15);
    root->right->right=new node(16);
    root->right->right->right=new node(17);
    
    if(isBalanced(root)!=-1)cout<<"YES";
    else cout<<"NO";
    
}