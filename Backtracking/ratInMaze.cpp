#include<bits/stdc++.h>
using namespace std;
int sol[10005][10005];
int maze[10005][10005];
int n;

bool isSafe(int i,int j)
{
    if(i<n&&j<n&&maze[i][j]==1)return true;
    else return false;
}
 
bool solveMazeRec(int i,int j)
{
    if(i==n-1&&j==n-1)
    {
        sol[i][j]=1;return true;
    }
    if(isSafe(i,j)==true)
    {
        sol[i][j]=1;
        if(solveMazeRec(i+1,j)==true)return true;
        if(solveMazeRec(i,j+1)==true)return true;
        sol[i][j]=0;
    }
    return false;
}

bool solveMaze()
{
    if(solveMazeRec(0,0)==false)return false;
    else {
        return true;
    }
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cin>>maze[i][j];
    }
    
    if(solveMaze()==true)
    {
        cout<<"Yes"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {cout<<sol[i][j]<<" ";}
            cout<<endl; 
        }
    }
    else
    {
        cout<<"No"<<endl;
    }
    

    return 0;
}