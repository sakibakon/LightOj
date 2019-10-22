#include<bits/stdc++.h>
using namespace std;
char s[9];

int zfun()
{
    int z[9];
    int left, right;
    z[0]=left=right=0;
    int len= strlen(s);
    int ma=0;
    for(int i=1; i<len; i++){
        if(i<=right)
            z[i] = min(z[i-left], right-i+1);
        while(i+z[i] <len && s[i+z[i]]==s[z[i]] )
        {
            z[i]++;
        }
        if(i + z[i] -1 > right){left= i; right= i+ z[i] -1;}
        printf("%d\n", z[i-1]);
        if(ma < z[i])ma= z[i];
    }
    return ma;
}
int main()
{
    int t, kk, r;


    scanf("%d", &t);
    kk=t;

    while(t--){

       scanf(" %s", s);
        int a=zfun();
        printf("%d\n", a);
    }

    return 0;
}

