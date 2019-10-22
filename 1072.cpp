#include<bits/stdc++.h>
using namespace std;
#define pi 2*acos(0.0)
int main()
{
   int t, casee=1;
   scanf("%d", &t);
   while(casee<=t){
        double R,rr, n, theta, temp, low,high, mid;
        scanf("%lf %lf", &R, &n);
        if(n==2){
             printf("Case %d: %lf\n", casee++, R/2);
            continue;
        }
        theta = pi/n;
        low=0;
        high=R;
        for(int i=0; i<50 ; i++){
            mid= low+((high-low)/2);
            rr=R-mid;
            temp=asin(mid/rr);
            if(temp>theta){
                high = mid;
            }
            else{ low= mid;  }
        }
        printf("Case %d: %lf\n", casee++, mid);



   }
}
