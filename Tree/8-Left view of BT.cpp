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

ll maxlevel=0;
//maxlevel represent,we've printed the left node of its value level
//while level in func store,node at current level

//recursive
void leftview(node* root,ll level)
{
    if(root==NULL)return;
    if(maxlevel<level)
    {
        cout<<root->key<<" ";
        maxlevel=level;
    }
    leftview(root->left,level+1);
    leftview(root->right,level+1);
}

//iterative
void printleftView(node* root)
{
    if(root==NULL)return;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        ll count=q.size();
        for(ll i=0;i<count;i++)
        {
            node* curr=q.front();q.pop();
            if(i==0)cout<<curr->key<<" ";
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
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
    
    leftview(root,1);
    cout<<endl;
    printleftView(root);
}