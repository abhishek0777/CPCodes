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

/*
Count nodes in a complete binary tree
*/

ll countNodes(node* root)
{
    ll lh=0,rh=0;
    node* curr=root;
    while(curr!=NULL)
    {
        lh++;
        curr=curr->left;
    }
    curr=root;
    while(curr!=NULL)
    {
        rh++;
        curr=curr->right;
    }
    if(lh==rh)return ((1LL<<lh)-1);
    return countNodes(root->left)+countNodes(root->right)+1;
}

int main()
{ 
    node* root=new node(20);
    root->left=new node(5);
    root->right=new node(15);
    root->left->left=new node(3);
    root->left->right=new node(2);
    
    cout<<countNodes(root); 
}