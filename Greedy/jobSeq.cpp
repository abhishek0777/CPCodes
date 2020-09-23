/*
    STATEMENT:
    Given an array of jobs where every job has a deadline and associated profit
    if the job is finished before the deadline. 
    It is also given that every job takes single unit of time,
    so the minimum possible deadline for any job is 1.
    How to maximize total profit if only one job can be scheduled at a time.

    Algo :
    1) Sort all jobs in decreasing order of profit.
    2) Iterate on jobs in decreasing order of profit.For each job , do the following :
    a)Find a time slot i, such that slot is empty and i < deadline and i is greatest.Put the job in
    this slot and mark this slot filled.
    b)If no such i exists, then ignore the job.

*/
#include<bits/stdc++.h>
using namespace std;

bool sortfun(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.second>b.second;
}

int main()
{
    int n;cin>>n;
    int d[n],p[n];
    for(int i=0;i<n;i++)cin>>d[i];
    for(int i=0;i<n;i++)cin>>p[i];
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back(make_pair(d[i],p[i]));
    }
    sort(v.begin(),v.end(),sortfun);

    bool slot[n];
    for(int i=0;i<n;i++)slot[i]=false;

    int res=0;

    for(int i=0;i<n;i++)
    {
        for(int j=min(n,v[i].first)-1;j>=0;j--)
        {
            if(slot[j]==false)
            {
                slot[j]=true;
                res+=v[i].second;
                break;
            }
        }

    }
    cout<<res;

}