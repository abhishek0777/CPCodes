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

//efficient approach : O(n)

ll res=0;

//this func return height but update the diameter in res variable
ll height(node* root)
{
    if(root==NULL)return 0;
    ll lh=height(root->left);
    ll rh=height(root->right);
    res=max(res,1LL+lh+rh);
    return (1LL+max(lh,rh));
}



int main()
{
    node* root=new node(20);
    root->left=new node(5);
    root->right=new node(15);
    root->left->left=new node(3);
    root->left->right=new node(2);
    
    height(root);
    cout<<res;
}