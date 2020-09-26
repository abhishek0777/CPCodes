/*
         fix first character then recursively call function for next part.
*/

#include<bits/stdc++.h>
using namespace std;

void permute(string s,int l,int r)
{
    if(l==r)
    {
        cout<<s<<endl;
        return;
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(s[i],s[l]);
            permute(s,l+1,r);
            swap(s[i],s[l]);
        }
    }
    

}
int main()
{
    string s;cin>>s;
    permute(s,0,s.length()-1);
}