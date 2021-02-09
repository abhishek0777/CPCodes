#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//MO's algorithm is to pre-process all queries so that result of one query can be used in next query
/*
algorithm
1.Sort all queries in a way that queries with L values from 0 to sqrt(n)-1 are put together,then all queries from sqrt(n) to 2*sqrt(n)-1, and so on.All queries within a block are sorted in increasing order of R.
2.Process all queries one by one in a way that every query uses sum computed in the previous query.
  (i) Let 'sum' be sum of previous query
  (ii) Remove extra elements of previous query.
  (iii) Add new elements of current query.

----------------------------------------------------------
Important Observations:
1. All queries are known beforehead so that they  can be preprocessed.
2.It can't work for problems where we have update operations also mixed with sum queries.
3. MO's algorithm can only be used for query problems where a query can be computed from results of the previous query.One more such example is maximum and minimum.

test input:
9 3
1 1 2 1 3 4 5 2 8
0 4
1 3
2 4
*/
ll len;
bool mycmp(pair<ll,ll> x,pair<ll,ll> y)
{
    //if L belongs to different blocks
    if(x.first/len!=y.first/len)return (x.first/len<y.first/len);
    //if same,sort according to R
    return (x.second<y.second);
    
}
int main()
{
    ll n,m;cin>>n>>m;ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    vector<pair<ll,ll>> query;
    for(ll i=0;i<m;i++)
    {
        ll l,r;cin>>l>>r;
        query.push_back({l,r});
    }
    len=sqrt(n);
    sort(query.begin(),query.end(),mycmp);
    //initialize current L and R and sum
    ll currL=0,currR=0,currSum=0;
    for(ll i=0;i<m;i++)
    {
        ll L=query[i].first;
        ll R=query[i].second;
        //remove extra elements of previous range
        //for ex if previous range is [0,3] and current range is [2,5],
        //then 0 & 1 are subtracted
        while(currL<L)
        {
            currSum-=a[currL];
            currL++;
        }
        //Add elements of current range
        while(currL>L)
        {
            currSum+=a[currL-1];
            currL--;
        }
        while(currR<=R)
        {
            currSum+=a[currR];
            currR++;
        }
        
        //remove elements of previous range.previous is [0,10] and curr[3,8],so remove 9 & 10
        while(currR>R+1)
        {
            currSum-=a[currR-1];
            currR--;
        }
        cout<<L<<" "<<R<<" "<<currSum<<endl;
    }
}