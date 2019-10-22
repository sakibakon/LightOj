#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
#define maxx 1000000000000
using namespace std;
ll cr[109], n, w, k;
ll dp[110][110];
ll fun(ll k , ll indx)
{
    if(k==0 || indx>=n)return 0;
    if(dp[indx][k]!= -1)return dp[indx][k];
    ll i;
    for(i=indx; i<n; i++){
        if(cr[i]>cr[indx]+w )break;
    }
    ll tm=0;
    tm= (i-indx) + fun(k-1, i);
    tm=max(tm, fun(k, indx+1) );
    dp[indx][k]=tm;
    return tm;
}
int main()
{
    IOS
    ll t;
    cin>>t;
    for(ll cs=1; cs<=t; cs++)
    {
        cin>>n>>w>>k;
        for(ll i=0; i<n; i++){
            ll a, b;
            cin>>a>>b;
            cr[i]=b;
        }
        memset(dp, -1, sizeof dp);
        sort(cr, cr+n);
        cout<<"Case "<<cs<<": "<<fun(k, 0)<<endl;

    }

    return 0;
}

