#include<bits/stdc++.h>
#define ll long long int
using namespace std;
struct node{
  ll key;
  node* left;
  node* right;
  node(ll k)
  {
      key=k;
      left=NULL;
      right=NULL;
  }
  
};

//complexity: height of BST
// it is at most h+1 comparison


//recursive
//Auxiliary space : O(h)
bool search1(node* root,ll k)
{
    if(root==NULL)return false;
    if(root->key==k)return true;
    if(root->key<k)search1(root->right,k);
    if(root->key>k)search1(root->left,k);
}
//iterative
// Auxiliary space : O(1)
bool search2(node* root,ll k)
{
    while(root!=NULL)
    {
        if(root->key==k)return true;
        else if(root->key<k)root=root->right;
        else root=root->left;
    }
    return false;
}
int main()
{
    node* root=new node(15);
    root->left=new node(5);
    root->left->left=new node(3);
    root->right=new node(20);
    root->right->right=new node(80);
    root->right->left=new node(18);
    root->right->left->left=new node(16);
    
    ll key=17;
    if(search1(root,key))cout<<"YES\n";
    else cout<<"NO\n";
    
    if(search2(root,key))cout<<"YES\n";
    else cout<<"NO\n";
}