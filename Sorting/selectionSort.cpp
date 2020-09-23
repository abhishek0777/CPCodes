/*
    The selection sort algorithm sorts an array by repeatedly finding the minimum element 
    (considering ascending order) from unsorted part and putting it at the beginning. 
    The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

*/

#include<bits/stdc++.h>
using namespace std;

void selectionSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_index=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min_index])
            min_index=j;
        }
        int temp=a[i];
        a[i]=a[min_index];
        a[min_index]=a[i];
    }

    for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    selectionSort(a,n);
}