#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
long double f(long double x){
    return (x*x + sqrtl(x));
}
int main(){
    FAST
    long double c,ans;
    cin>>c;
    long double l=0,r=sqrtl(c);
    while (l<=r)
    {
        long double mid=(l+r)/2;
        if(f(mid)>=c){
            ans=mid;
            r=mid-0.00001;
        }
        else{
            l=mid+0.00001;
        }
    }
    cout<<setprecision(16)<<ans;
    return 0;
}