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

ll board[100][100];
ll n;

bool isSafe(ll row,ll col)
{
    for(ll i=0;i<col;i++)
    {
        if(board[row][i]==1)return false;
    }

    for(ll i=row,j=col;i>=0,j>=0;i--,j--)
    {
        if(board[i][j]==1)return false;
    }
    
    for(ll i=row,j=col;(i<n)&&(j>=0);i++,j--)
    {
        if(board[i][j]==1)return false;
    }
    
    return true;
}


bool NQueen(ll col)
{
    if(col==n)return true;
    
    for(ll i=0;i<n;i++)
    {
        if(isSafe(i,col))
        {
            board[i][col]=1;
            if(NQueen(col+1))return true;
            board[i][col]=0;
        }
    }
    return false;
}

void solve()
{
    cin>>n;
    if(NQueen(0))
    {
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            cout<<board[i][j]<<" ";
            cout<<endl;
        }
    }
    else
    {
        cout<<"Impossible to place";
    }
    
}

int main()
{
    solve();
    return 0;  
}