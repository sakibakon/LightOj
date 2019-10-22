#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++ )
    {
        ll n;
        cin>>n;
        vector<ll>v[2*n], ans[2*n], ans1[2*n];
        for(ll j=1; j<=n; j++){
            for(ll k=0; k<j; k++){
                ll tm;
                cin>>tm;
                v[j].push_back(tm);
                ans[j].push_back(0);
                ans1[j].push_back(0);
            }
        }
        for(ll j=n+1; j<(2*n); j++){
            for(ll k=0; k<(2*n)-j; k++){
                ll tm;
                cin>>tm;
                v[j].push_back(tm);
                ans[j].push_back(0);
                ans1[j].push_back(0);
            }
        }
       /* for(ll j=1; j<=2*n-1; j++){
            for(ll k=0; k<v[j].size(); k++){
                cout<<v[j][k]<<" ";
            }
            cout<<endl;
        }*/
        ans[1][0]=v[1][0];
        for(ll j=1; j<n; j++){
            for(ll k=0; k<v[j].size(); k++){
                ans[j+1][k]=max(v[j+1][k]+ans[j][k], ans[j+1][k] );
                ans[j+1][k+1]=max(v[j+1][k+1]+ans[j][k], ans[j+1][k+1] );
            }
        }
        ans1[2*n-1][0]=v[2*n-1][0];
        for(ll j=2*n-1; j>n; j--){
            for(ll k=0; k<v[j].size(); k++){
                ans1[j-1][k]=max(v[j-1][k]+ans1[j][k], ans1[j-1][k] );
                ans1[j-1][k+1]=max(v[j-1][k+1]+ans1[j][k], ans1[j-1][k+1] );
            }
        }
        ll mx=0;
        for(ll j=0; j<n; j++){
            mx=max(ans[n][j]+ans1[n][j]-v[n][j], mx);
        }
        cout<<"Case "<<i<<": "<<mx<<endl;
    }
}
