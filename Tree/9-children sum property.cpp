//sum of node is equal to sum of left child and right child
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


bool isCSum(node* root)
{
    if(root==NULL)return true;
    if(root->left==NULL&&root->right==NULL)return true;
    ll sum=0;
    if(root->left)sum+=root->left->key;
    if(root->right)sum+=root->right->key;
    
    return (sum==root->key)&&(isCSum(root->left))&&(isCSum(root->right));
}

int main()
{
    node* root=new node(20);
    root->left=new node(5);
    root->right=new node(15);
    root->left->left=new node(3);
    root->left->right=new node(2);
    
    if(isCSum(root))cout<<"YES";
    else cout<<"NO";
}