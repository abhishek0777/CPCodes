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

//burn a binary tree from a leaf 
//Two things done: (i) return height  
//           (ii) set dist if given leaf is a descendant
// res is shared by all function calls
//Initially:dist= -1
//dist stores distance of current node from leaf node if leaf is descendant of it,else return -1

ll res=0;
ll burntime(node* root,ll leaf,ll &dist)
{
    if(root==NULL)return 0;
    if(root->key==leaf){
        dist=0;return 1;
    }
    ll ldist=-1,rdist=-1;
    ll lh=burntime(root->left,leaf,ldist);
    ll rh=burntime(root->right,leaf,rdist);
    if(ldist!=-1)
    {
        dist=ldist+1;
        res=max(res,dist+rh);
    }
    else if(rdist!=-1)
    {
        dist=rdist+1;
        res=max(res,dist+lh);
    }
    return 1+max(lh,rh);
}


int main()
{ 
    node* root=new node(20);
    root->left=new node(5);
    root->right=new node(15);
    root->left->left=new node(3);
    root->left->right=new node(2);
    ll d=-1;
    burntime(root,3,d);
    cout<<res;
    
    
}