#include<bits/stdc++.h>
#include<string>
#define N 20005
using namespace std;
int ch[N][10], ss=0, isWord[N];
void inl()
{
    memset(ch, 0, sizeof ch);
    memset(isWord, 0, sizeof isWord);
    ss=0;
}
bool insertt(string s)
{
    int u=0;
    for(int i=0; i<s.size(); i++){
        int c=s[i]-'0';
        if(!ch[u][c])ch[u][c]=++ss;
        u=ch[u][c];
        if(isWord[u]==1)return true;
    }
    isWord[u]=1;
    return false;
}
bool searchh(string s)
{
    int u=0;
    ///not search full string. last element is not include in the search.
    for(int i=0; i<s.size()-1; i++){
        int c=s[i]-'0';
        u=ch[u][c];
        if(isWord[u]==1)return true;
    }
    return false;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++ ){
        int n, f=0;
        inl();
        vector<string>v;
        string s1, s2, s3;
        cin>>n;
        for(int j=1; j<=n; j++){
            cin>>s1;
            if(insertt(s1))f=1;
            v.push_back(s1);
        }
        if(f==1){printf("Case %d: NO\n", i); continue;}
        for(int j=0; j<v.size(); j++){
            if(searchh(v[j])){
                f=1;
                break;
            }
        }

        if(f==1){printf("Case %d: NO\n", i);}
        else{printf("Case %d: YES\n", i); }
    }


    return 0;
}
