/*
SPace optimized iterative preorder tree traversal
*/
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

void preorder(node* root)
{
    if(!root)return;
    stack<node*> st;
    node* curr=root;
    while(curr||!st.empty())
    {
        while(curr)
        {
            cout<<curr->key<<" ";
            if(curr->right)st.push(curr->right);
            curr=curr->left;
        }
        if(!st.empty()){
            curr=st.top();st.pop();
        }
    }
}


int main()
{
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    
    //space optimized preorder
    preorder(root);
    
}