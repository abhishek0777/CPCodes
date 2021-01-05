#include <bits/stdc++.h>
#include <algorithm>
#define ll long long int
#define pii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

#define pb push_back
#define mp make_pair

#define MOD 1000000007
#define inf 1000000007

//Optimal strategy for a game
//Input : 20 5 4 6     ,no of coins always even
//o/p :25

// ------ GREEDY
//if i want to win,then just find sum of even placed coins and odd placed amd whichever sum is 
// greater pick that one,if odd has more sum then pick 1st coin otherwise pick nth coin


//----DP
//But if we want to get the maximum sum with winning ,then the solution will be different

ll sol(ll arr[],ll i,ll j)
{
   if(i+1==j)return max(arr[i],arr[j]);
   
   return max(
                  arr[i]+min( sol(arr,i+2,j),sol(arr,i+1,j-1) ),
                  arr[j]+min( sol(arr,i+1,j-1),sol(arr,i,j-2) )
             );
}
int main() {
    FAST
    ll n;cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)cin>>arr[i];
    cout<<sol(arr,0,n-1);
	return 0;
}
