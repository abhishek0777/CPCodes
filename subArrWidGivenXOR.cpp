/*
    An Efficient Solution solves the above problem in O(n) time. Let us call the XOR of all elements in the range [i+1, j] as A,
    in the range [0, i] as B, and in the range [0, j] as C. If we do XOR of B with C, the overlapping elements in [0, i] from B and C zero out
    and we get XOR of all elements in the range [i+1, j], i.e. A. Since A = B XOR C, we have B = A XOR C.
    Now, if we know the value of C and we take the value of A as m, we get the count of A as the count of all B satisfying this relation.
    Essentially, we get the count of all subarrays having XOR-sum m for each C. As we take sum of this count over all C, we get our answer
*/
#include<bits/stdc++.h>
using namespace std;

void countArr(int a[],int n,int m)
{
    int xorArr[n];
    xorArr[0]=a[0];

    for(int i=1;i<n;i++)
    xorArr[i]=a[i]^xorArr[i-1];

    unordered_map<int,int> mp;
    int ans=0;

    for(int i=0;i<n;i++)
    {
        int temp=m^xorArr[i];

        ans+=((long long)mp[temp]);

        if(xorArr[i]==m)ans++;

        mp[xorArr[i]]++;
    }

    cout<<ans;
}
int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int m;cin>>m;
    countArr(a,n,m);
}