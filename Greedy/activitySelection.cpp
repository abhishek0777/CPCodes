/*
STATEMENT :
You are given n activities with their start and finish times.
Select the maximum number of activities that can be performed by a single person,
assuming that a person can only work on a single activity at a time.

    ALGO :
    1) Sort the activities according to their finishing time
    2) Select the first activity from the sorted array and print it.
    3) Do following for remaining activities in the sorted array.
    …….a) If the start time of this activity is greater than or equal to the finish time of previously selected activity then select this activity and print it.

    In the following C implementation, it is assumed that the activities are already sorted according to their finish time.

*/

#include<bits/stdc++.h>
using namespace std;

bool sortfun(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.second<b.second;
}

int main()
{
    int n;cin>>n;
    int s[n],f[n];
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++)cin>>f[i];
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back(make_pair(s[i],f[i]));
    }
    sort(v.begin(),v.end(),sortfun);

    int j=0;int cnt=1;
    for(int i=1;i<n;i++)
    {
        if(v[i].first>=v[j].second)
        {
            j=i;
            cnt++;
        }
    }
    cout<<cnt;

    return 0;

}