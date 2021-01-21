
#include<bits/stdc++.h>
#include<algorithm>
#define ll long long int
#define pii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define inf INT_MAX

ll add(ll x,ll y){ll res=x+y; return (res>=MOD?res-MOD:res);}
ll mul(ll x,ll y){ll res=x*y; return (res>=MOD?res%MOD:res);}
ll sub(ll x,ll y){ll res=x-y; return (res<0?res+MOD:res);}

//code for rat and maze  and if there occur path from top leftt to bottom right
//given a binary matrix where 0 indicates block cell and 1 is allowed cell

vector<vector<ll>> maze,sol;
ll n;
bool isSafe(ll i,ll j)
{
    return(i<n&&j<n&&maze[i][j]==1);
}
bool solveMaze(ll i,ll j)
{
    if((i==n-1)&&(j==n-1)&&(maze[i][j]==1))
    {
        sol[i][j]=1;
        return false;
    }
    if(isSafe(i,j))
    {
        sol[i][j]=1;
        if(solveMaze(i+1,j))return true;
        else if(solveMaze(i,j+1))return true;
        sol[i][j]=0;
    }
    return false;
}

void solve()
{
    cin>>n;
    maze.assign(n,vector<ll>(n));
    sol.assign(n,vector<ll>(n));
    for(ll i=0;i<n;i++)
    for(ll j=0;j<n;j++)cin>>maze[i][j];
    
    if(solveMaze(0,0))
    {
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)cout<<sol[i][j]<<" ";
            cout<<endl;
        }
    }
    else
    {
        cout<<"There is no path for rat to reach at butter location";
    }
} 

int main()
{
    solve();
    return 0;  
}