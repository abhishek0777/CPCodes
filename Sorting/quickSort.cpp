/*
    use gfg for better explanation

    INSHORT : take a pivot element and place it correct position in array such that 
    all elements left to it are less than pivoted element and elements right to it are greater than it

*/

#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;

    return i+1;
}

void quickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(a,low,high);

        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}
int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    quickSort(a,0,n-1);

    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}