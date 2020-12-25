#include<bits/stdc++.h>
using namespace std;
#define V 4

int minKey(int key[],bool mstSet[])
{
    int min=INT_MAX;
    int mini;
    for(int i=0;i<V;i++)
    {
        if(mstSet[i]==false&&key[i]<min)
        {
            min=key[i];
            mini=i;
        }
    }
    return mini;
}

void printMST(int parent[],int g[V][V])
{
    for(int i=1;i<V;i++)
    {
        cout<<parent[i]<<"-"<<i<<"=>"<<g[parent[i]][i]<<endl;
    }
}

void mst(int g[V][V])
{
    int key[V];
    for(int i=0;i<V;i++)key[i]=INT_MAX;
    
    key[0]=0;
    int parent[V];
    parent[0]=-1;
    bool mstSet[V];
    for(int i=0;i<V;i++)mstSet[i]=false;
    
    for(int i=0;i<V-1;i++)
    {
        int u=minKey(key,mstSet);
        
        mstSet[u]=true;
        
        for(int j=0;j<V;j++)
        {
            if(g[u][j]!=0&&mstSet[j]==false&&g[u][j]<key[j])
            {
                parent[j]=u;key[j]=g[u][j];
            }
        }
        
    }
    
    printMST(parent,g);
}

int main()
{
     
    int v,e;
    cin>>v>>e;
    int g[V][V];
    for(int i=0;i<v;i++)
    for(int j=0;j<v;j++)
    g[i][j]=0;
    for(int i=0;i<e;i++)
    {
        int a,b;cin>>a>>b;
        cin>>g[a][b];
        g[b][a]=g[a][b];
    }
    
    mst(g);
    
}