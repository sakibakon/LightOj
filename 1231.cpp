#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
using namespace std;
ll MOD = 100000007;
ll aa[55], bb[55], ans, n, value, dp[55][22][1005];
ll fun(ll i, ll t, ll x )
{
    if(i==n){
        if(x==0)return 1;
        else return 0;
    }
    ll in1=0, in2=0;
    if(dp[i][t][x]!=-1)return dp[i][t][x];
    if(t<bb[i] && x-aa[i]>=0){
        in1=fun(i, t+1, x-aa[i]);
    }
    in2=fun(i+1,0,x);
    dp[i][t][x]=(in1+in2)%MOD;
    return dp[i][t][x];

}
int main()
{
    ll tast;
    cin>>tast;

    for(ll t=1; t<=tast; t++){
        memset(dp, -1, sizeof(dp) );
        cin>>n>>value;
        for(ll i=0; i<n; i++ )cin>>aa[i];
        for(ll i=0; i<n; i++ )cin>>bb[i];
        ans=fun(0, 0, value )%MOD;
        cout<<"Case "<<t<<": "<<ans<<endl;

    }

    return 0;
}

