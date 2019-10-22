#include<bits/stdc++.h>
#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll root[100000][1], sv[100000], av[100000], f=0, ans=0;
vector<ll>tree[100000];
void bfs_(ll rr)
{
    ll skb=0;
    bool visit[100000];
    memset(visit, false, sizeof visit);
    queue<ll>q;
    q.push(rr);
    visit[root[rr][0]]=true;
    visit[rr]=true;
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        for(ll i=0; i<tree[u].size(); i++){
            if(visit[tree[u][i]]==false)
            {
                visit[tree[u][i]]==true;
                q.push(tree[u][i]);
                skb=max(skb, sv[tree[u][i]] );

            }
        }
    }
    if(skb<sv[root[rr][0] ])f=-1;
    if(skb==0){ }
    else ans+=(skb-sv[root[rr][0] ]);

}

void bfs(ll rt)
{
    bool visit[100000];
    memset(visit, false, sizeof visit);
    queue<ll>q;
    q.push(rt);
    visit[rt]=true;
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        for(ll i=0; i<tree[u].size(); i++){
            if(visit[tree[u][i]]==false)
            {
                visit[tree[u][i]]==true;
                if(sv[tree[u][i]==-1]){
                    bfs_(tree[u][i]);
                }
                else{
                    q.push(tree[u][i]);
                    ans+=( sv[tree[u][i] ] - sv[root[tree[u][i]][0] ]  );
                }
            }
        }
    }
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=2; i<=n; i++){
        ll t;
        cin>>t;
        root[i][t];
        tree[i].push_back(t);
        tree[t].push_back(i);
    }
    for(ll i=1; i<=n; i++){
        cin>>sv[i];
    }
    bfs(1);
    if(f==-1)cout<<-1;
    else cout<<ans;

    return 0;
}
