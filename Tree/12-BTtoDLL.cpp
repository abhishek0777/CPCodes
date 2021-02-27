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

//left as prev and right as next for Doubly linked list 
//order in linked list will be inorder 

node* prv=NULL;
node* BTtoDLL(node* root)
{
    if(root==NULL)return NULL;
    node* head=BTtoDLL(root->left);
    if(prv==NULL)head=root;
    else
    {
        root->left=prv;
        prv->right=root;
    }
    prv=root;    
    BTtoDLL(root->right);
    return head;
}

int main()
{
    node* root=new node(20);
    root->left=new node(5);
    root->right=new node(15);
    root->left->left=new node(3);
    root->left->right=new node(2);
    
    node* head=BTtoDLL(root);
    
    while(head)
    {
        cout<<head->key<<" ";
        head=head->right;
    }
    
}