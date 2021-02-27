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

//Diameter of a tree: longest path b/w two leaf nodes,return number of nodes on this path

//naive approach : O(n*n)

ll height(node* root)
{
    if(root==NULL)return 0;
    return 1+max(height(root->left),height(root->right));
}

ll diameter(node* root)
{
    if(root==NULL)return 0;
    ll d1=1+height(root->left)+height(root->right);
    ll d2=diameter(root->left);
    ll d3=diameter(root->right);
    return max(d1,max(d2,d3));
}

int main()
{
    node* root=new node(20);
    root->left=new node(5);
    root->right=new node(15);
    root->left->left=new node(3);
    root->left->right=new node(2);
    
    cout<<diameter(root);
    
}