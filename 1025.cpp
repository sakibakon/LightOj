#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
#define N 20000
using namespace std;
string s;
ll dp[65][65];
ll fun(ll l, ll r)
{
    if(l>r)return 0;
    if(l==r)return 1;
    if(dp[l][r]!=-1)return dp[l][r];
    ll ans=0;
    if(s[l]==s[r]){
        ans=1+fun(l+1, r)+fun(l, r-1);
    }
    else{
        ans=fun(l+1, r)+fun(l, r-1)-fun(l+1, r-1);
    }
    dp[l][r]=ans;
    return ans;
}
int main()
{
    IOS
    ll t;
    cin>>t;
   // getchar();
    for(ll i=1; i<=t; i++){
        memset(dp, -1, sizeof dp);
        cin>>s;
        cout<<"Case "<<i<<": "<<fun(0, s.size()-1)<<endl;

    }


    return 0;
}

