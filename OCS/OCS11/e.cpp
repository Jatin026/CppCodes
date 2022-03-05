#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
#define M_PI 3.14159265358979323846
using namespace std;
long double xc(long double theta, long double distance){
    return distance*cos(theta);
}
long double yc(long double theta, long double distance){
    return distance*sin(theta);
}
void solve(){
    long double px,py,vx,vy,a,b,c,d,theta,p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y,p5x,p5y,p6x,p6y,p7x,p7y;
    cin>>px>>py>>vx>>vy>>a>>b>>c>>d;
    theta=atan(vy/vx);
    if(vx<0) theta=M_PI+theta;
    else if(vy<0) theta=2*M_PI+theta;
    p1x=px+xc(theta,b);
    p1y=py+yc(theta,b);
    p2x=px-yc(theta,a/2);
    p2y=py+xc(theta,a/2) ;
    p3x=px-yc(theta,c/2);
    p3y=py+xc(theta,c/2);
    p4x=px-xc(theta,d)-yc(theta,c/2);
    p4y=py-yc(theta,d)+xc(theta,c/2);
    p5x=px-xc(theta,d)+yc(theta,c/2);
    p5y=py-yc(theta,d)-xc(theta,c/2);
    p6x=px+yc(theta,c/2);
    p6y=py-xc(theta,c/2);
    p7x=px+yc(theta,a/2);
    p7y=py-xc(theta,a/2);
    cout<<fixed<<setprecision(12)<<p1x<<"  "<<p1y<<"\n";
    cout<<fixed<<setprecision(12)<<p2x<<"  "<<p2y<<"\n";
    cout<<fixed<<setprecision(12)<<p3x<<"  "<<p3y<<"\n";
    cout<<fixed<<setprecision(12)<<p4x<<"  "<<p4y<<"\n";
    cout<<fixed<<setprecision(12)<<p5x<<"  "<<p5y<<"\n";
    cout<<fixed<<setprecision(12)<<p6x<<"  "<<p6y<<"\n";
    cout<<fixed<<setprecision(12)<<p7x<<"  "<<p7y<<"\n";
}
int main(){
    FAST
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}