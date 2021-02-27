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

ll preidx=0;
node* Ctree(ll in[],ll pre[],ll s,ll e)
{
    if(s>e)return NULL;
    node* root=new node(pre[preidx++]);
    
    ll inidx;
    for(ll i=s;i<=e;i++)
    {
        if(in[i]==root->key)
        {
            inidx=i;
            break;
        }
    }
    root->left=Ctree(in,pre,s,inidx-1);
    root->right=Ctree(in,pre,inidx+1,e);
    return root;
}


int main()
{
    
    ll n=5;
    ll in[]={20,10,40,30,50};
    ll pre[]={10,20,30,40,50};
    node* root=Ctree(in,pre,0,n-1);
    cout<<root->key;
    
}