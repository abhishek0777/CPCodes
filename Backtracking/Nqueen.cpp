#include<bits/stdc++.h>
using namespace std;
int n;
int board[1005][1005];

bool isSafe(int r,int c)
{
    for(int i=0;i<c;i++)
    {
        if(board[r][i])return false;
    }

    for(int i=r,j=c;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j])return false;
    }
    for(int i=r,j=c;i<n&&j>=0;i++,j--)
    {
        if(board[i][j])return false;
    }
    return true;
}

bool solveRec(int col)
{
    if(col==n)
    return true;
    for(int i=0;i<n;i++)
    {
        if(isSafe(i,col))
        {
            board[i][col]=1;
            if(solveRec(col+1))
            return true;
            board[i][col]=0;
        }
        

        
    }
    return false;
}

bool solve()
{
    if(solveRec(0)==false)
    return false;
    else return true;
}
int main()
{
    cin>>n;
    if(solve()==false)cout<<"Impossible"<<endl;
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    

    return 0;
}