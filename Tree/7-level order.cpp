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


void levelOrder(node* root)
{
    queue<node*> q;
    q.push(root);q.push(NULL);
    while(q.size()>1)
    {
        node* curr=q.front();q.pop();
        if(curr==NULL){cout<<"\n";q.push(NULL);continue;}
        cout<<curr->key<<" ";
        if(curr->left)q.push(curr->left);
        if(curr->right)q.push(curr->right);
    }
}

void levelOrderr(node* root)
{
    if(root==NULL)return;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        ll count=q.size();
        while(count--)
        {
            node* curr=q.front();q.pop();
            cout<<curr->key<<" ";
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        cout<<"\n";
    }
}


int main()
{
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    
    // method -1
    levelOrder(root);
    cout<<endl;
    //method-2
    levelOrderr(root);
    
}