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

void iterativeInorder(node* root)
{
    stack<node*> st;
    node* curr=root;
    while(curr!=NULL||!st.empty())
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();st.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
    }
}

void iterativePreorder(node* root)
{
    stack<node*> st;
    node* curr=root;
    st.push(root);
    
    while(!st.empty())
    {
        node* curr=st.top();
        cout<<curr->key<<" ";
        st.pop();
        
        
        if(curr->right!=NULL)st.push(curr->right);
        if(curr->left!=NULL)st.push(curr->left);
    }
}

void iterativePostorder(node* root)
{
    if(root==NULL)return;
    
    stack<node*> st1,st2;
    st1.push(root);
    //run while first stack is not empty
    while(!st1.empty()){
        node* curr=st1.top();
        st1.pop();
        st2.push(curr);
        
        //push left & right children of removed item to st1
        if(curr->left!=NULL)st1.push(curr->left);
        if(curr->right!=NULL)st1.push(curr->right);
    }
    
    while(!st2.empty())
    {
        node* curr=st2.top();st2.pop();
        cout<<curr->key<<" ";
    }
}

int main()
{
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    
    cout<<"Inorder : ";
    iterativeInorder(root);
    cout<<endl;
    
    cout<<"Preorder : ";
    iterativePreorder(root);
    cout<<endl;
    
    cout<<"Post order : ";
    iterativePostorder(root);
    
}