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

int main()
{
    node* root=new node(10);
    root->left=new node(5);
    root->right=new node(20);
    cout<<root->left->key;
}