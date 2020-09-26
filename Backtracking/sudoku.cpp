#include<bits/stdc++.h>
using namespace std;
int N;
int grid[1005][1005];

bool isSafe(int i,int j,int n)
{
        for(int k=0;k<N;k++)
        {
            if((grid[i][k]==n)||(grid[k][j]==n))
            return false;
        }
        int s=sqrt(N);

        int rs=i-i%s;
        int cs=j-j%s;

        for(int i=0;i<s;i++)
        {
            for(int j=0;j<s;j++)
            {
                if(grid[i+rs][j+cs]==n)
                return false;
            }
        }
        return true;
    
}


bool solve()
{
    int i,j;int f=1;
    for( i=0;i<N;i++)
    {
        for( j=0;j<N;j++)
        {
            if(grid[i][j]==0){f=-1;break;}
        }
        if(f==-1)break;
    }
    

    if(i==N&&j==N)return true;

    for(int n=1;n<=N;n++)
    {
        if(isSafe(i,j,n))
        {
            grid[i][j]=n;
            if(solve())
            return true;
            grid[i][j]=0;
        }
    }
    return false;
}


int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)cin>>grid[i][j];
    }
    if(solve()==true)
    {
        cout<<"Yes"<<endl;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            cout<<grid[i][j]<<" ";
            cout<<endl;
        }
    }
    else
    {
        cout<<"Impossible"<<endl;
    }
    
}