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
//lCA-Lowest common ancestor
//for naive,refer to video(create path vector for both elements.....)

//efficient solution
//assumption:both the values are present in a BT

node* lca(node* root,ll n1,ll n2)
{
    if(root==NULL)return NULL;
    if(root->key==n1||root->key==n2)return root;
    node* lca1=lca(root->left,n1,n2);
    node* lca2=lca(root->right,n1,n2);
    if(lca1!=NULL&&lca2!=NULL)return root;
    if(lca1!=NULL)return lca1;
    return lca2;
}


int main()
{ 
    node* root=new node(20);
    root->left=new node(5);
    root->right=new node(15);
    root->left->left=new node(3);
    root->left->right=new node(2);
    
    cout<<lca(root,3,15)->key;
    
}