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

//Test Input:
// 4
// 1 0 3 0
// 0 0 2 1
// 0 1 0 2
// 2 4 0 0
ll N;
ll grid[1000][1000];

bool isSafe(ll i,ll j,ll n)
{
    for(ll k=0;k<N;k++)
    {
        if(grid[k][j]==n||grid[i][k]==n)return false;
    }
    ll s=sqrt(N);
    ll rs=s*(i/s);
    ll cs=s*(j/s);
    
    for(ll p=0;p<s;p++)
    {
        for(ll q=0;q<s;q++)
        {
            if(grid[rs+p][cs+q]==n)return false;
        }
    }
    return true;
}

bool sudoku()
{
    ll f=1;
    ll i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(grid[i][j]==0)
            {
                f=-1;break;
            }
        }
        if(f==-1)break;
    }
    if(i==N&&j==N)return true;
    
    for(ll n=1;n<=N;n++)
    {
        if(isSafe(i,j,n))
        {
            grid[i][j]=n;
            if(sudoku())return true;
            grid[i][j]=0;
        }
    }
    return false;
}

void solve()
{
    cin>>N;
    for(ll i=0;i<N;i++)
    {
        for(ll j=0;j<N;j++)
        cin>>grid[i][j];
    }
    
    if(sudoku())
    {
        for(ll i=0;i<N;i++)
        {
            for(ll j=0;j<N;j++)
            cout<<grid[i][j]<<" ";
            cout<<endl;
        }
    }
    else
    {
        cout<<"Impossible to find";
    }
}

int main()
{
    solve();
    return 0;  
}