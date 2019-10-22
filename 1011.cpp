#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll couple, ans=0, lll=1;
ll cpl[18][18];
//map<ll, map<string, ll> >mp;
ll mp[17][1<<17];
ll Set(ll N,ll pos){return N=N | (1<<pos);}
ll reset(ll N,ll pos){return N= N & ~(1<<pos);}
bool check(ll N,ll pos){return (bool)(N & (1<<pos));}
ll mrg(ll arr ,ll po, ll cost)
{
    ll skb=0;
    if( mp[po][arr]!=-1 ){
        return mp[po][arr]+cost;
    }
    if(po==couple){
        return cost;
    }
    for(ll i=0; i<couple; i++){
        if(check(arr,i)==0){
            ll tmp_cost = mrg(Set(arr,i) , po+1, cost+cpl[po][i] );
            skb=max(skb, tmp_cost);
        }
    }
    mp[po][arr]=skb-cost;
    return skb;

}
int main()
{
    ll t;
    cin>>t;
    for(ll cs=1; cs<=t; cs++)
    {
        cin>>couple;

        for(ll i=0; i<couple; i++)
        {
            for(ll j=0; j<couple; j++)
            {
                cin>>cpl[i][j];
            }
        }
        ll arr=0;
        memset(mp,-1, sizeof mp);
        ans=mrg(arr , 0, 0 );
        cout<<"Case "<<cs<<": "<<ans<<endl;
        ans=0;



    }
}
