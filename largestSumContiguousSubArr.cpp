/*
      Kadane's Algorithm
      Initialize:
        max_so_far = 0
        max_ending_here = 0

        Loop for each element of the array
        (a) max_ending_here = max_ending_here + a[i]
        (b) if(max_so_far < max_ending_here)
                    max_so_far = max_ending_here
        (c) if(max_ending_here < 0)
                    max_ending_here = 0
        return max_so_far
*/
#include<bits/stdc++.h>
using namespace std;

void maxSum(int a[],int n)
{
    int x=0,y=0; //x=max ending here,y=max so far
    for(int i=0;i<n;i++)
    {
        x+=a[i];
        if(x>y)y=x;
        if(x<0)x=0;

    }
    cout<<y;
}
int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    maxSum(a,n);
}