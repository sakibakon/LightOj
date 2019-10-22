#include<bits/stdc++.h>
using namespace std;
double ab, ac, bc, ade, bdec, ratioo, ad, de, ae, s1, s2, sq1, sq2, abc;
int chack( ){
    de=(bc*ad)/ab;
    ae=(de*ac)/bc;
    s1=(ad+de+ae)/2;
    s2=(ab+ac+bc)/2;
    ade=sqrt(s1*(s1-ad)*(s1-de)*(s1-ae));
    abc=sqrt(s2*(s2-ab)*(s2-bc)*(s2-ac));
    bdec=abc-ade;
    sq1=ade/bdec;
    if(sq1 > ratioo){
            return 1;
    }
    else{
        return 2;
    }

}
int main()
{
    int t, tt=1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &ratioo);
        double low=0, high=ab;
        int b;
        for(int i=0; i<60; i++){
            ad=low+((high-low)/2);
            b=chack();

            if(b==1){
                high=ad;
                low=low;
            }
            else if(b==2){
                low=ad;
                high=high;
            }
        }
        printf("Case %d: %lf\n",tt++, ad);
    }
    return 0;
}
