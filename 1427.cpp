#include<bits/stdc++.h>
using namespace std;
#define N 250000
vector<int>val;
int ch[N][27], num[N], ss=0, f[N];
void inl()
{
    memset(ch, 0, sizeof ch);
    memset(num, 0, sizeof num);
    memset(f, 0, sizeof f);
    ss=0;
    val.clear();

}
void inser(char s[])
{
    int u=0;
    int len=strlen(s);
    for(int i=0; i<len; i++){
        int c=s[i]-'a';
        if(!ch[u][c]){
            ch[u][c]=++ss;
        }
        u=ch[u][c];
    }
    val.push_back(u);
    num[u]=0;
}
void build_fail()
{
    queue<int> q;
    int i;
    for(int i=0; i<26; i++){
        if(ch[0][i])
            q.push(ch[0][i]);
    }
    int r , u, v;
    while(!q.empty())
    {
        r=q.front();
        q.pop();
        for(int c=0; c<26; c++){
            u=ch[r][c];
            if(!u)
                continue;
            q.push(u);
            v=f[r];
            while(v && ch[v][c]==0)
                v=f[v];
            f[u]= ch[v][c];
        }
    }
}
void searc(char s[])
{
    int j=0;
    int len=strlen(s);
    for(int i=0; i<len; i++){
        int c= s[i]-'a';
        while(j && ch[j][c]==0)
            j=f[j];
        j=ch[j][c];
        int temp=j;
        while(temp){
            num[temp]++;
            temp=f[temp];
        }
    }
}
int main()
{
    int t, n;
    scanf("%d", &t);
    for(int cs=1; cs<=t; cs++)
    {
        char s1[1000001], s2[505];
        scanf("%d", &n);
        scanf(" %s", s1);
        while(n--){
            scanf(" %s", s2);
            inser(s2);
        }
        build_fail();
        searc(s1);
        cout<<"Case "<<cs<<":"<<endl;
        for(int i=0; i<val.size(); i++)printf("%d\n", num[val[i]]);
        inl();

    }
    return 0;
}
