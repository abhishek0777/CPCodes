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

void spiralMethod1(node* root)
{
    if(root==NULL)return;
    queue<node*> q;
    stack<ll> st;
    q.push(root);
    bool reverse=false;
    while(!q.empty())
    {
        ll count=q.size();
        for(ll i=0;i<count;i++)
        {
            node* curr=q.front();q.pop();
            if(reverse)st.push(curr->key);
            else
            {
                cout<<curr->key<<" ";
            }
            
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        if(reverse)
        {
            while(!st.empty())
            {
                cout<<st.top()<<" ";
                st.pop();
            }
        }
        reverse=!reverse;
        cout<<"\n";
    }
}


//algorithm for method-2
/*
1. Push root to the stack s1
2. while any of the two stacks is not empty
     while s1 is not empty
       (a)take out node ,print it
       (b)push children of the taken out node into s2
     while s2 is not empty
       (a)take out a node ,print it
       (b)push children of the taken out node into s1 in reverse order
         IMP* push right children then left children
*/

void spiralMethod2(node* root)
{
    if(root==NULL)return;
    stack<node*> s1,s2;
    s1.push(root);
    
    while(!s1.empty()||!s2.empty())
    {
        while(!s1.empty())
        {
            node* curr=s1.top();s1.pop();
            cout<<curr->key<<" ";
            if(curr->left);
            s2.push(curr->left);
            if(curr->right);
            s2.push(curr->right);
        }
        cout<<endl;
        while(!s2.empty())
        {
            node* curr=s2.top();s2.pop();
            cout<<curr->key<<" ";
            if(curr->right)
            s1.push(curr->right);
            if(curr->left)
            s1.push(curr->left);
        }
        cout<<endl;
    }
}




int main()
{
    node* root=new node(20);
    root->left=new node(5);
    root->right=new node(15);
    root->left->left=new node(3);
    root->left->right=new node(2);
    
    spiralMethod1(root);

    spiralMethod2(root);
    
}