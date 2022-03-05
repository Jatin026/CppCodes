#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
#define M_PI 3.14159265358979323846
using namespace std;
long double xc(long double theta, long double x, long double y){
    return x*cos(theta)-y*sin(theta);
}
long double yc(long double theta, long double x, long double y){
    return y*cos(theta)+x*sin(theta);
}
void solve(){
    long double px,py,vx,vy,a,b,c,d,theta,p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y,p5x,p5y,p6x,p6y,p7x,p7y;
    cin>>px>>py>>vx>>vy>>a>>b>>c>>d;
    theta=atan(vy/vx);
    if(vx<0) theta=M_PI+theta;
    else if(vy<0) theta=2*M_PI+theta;
    p1x=px;
    p1y=py;
    p2x=px;
    p2y=py+a/2 ;
    p3x=px ;
    p3y=py+c/2 ;
    p4x=px-d;
    p4y=py+c/2;
    p5x=px-d;
    p5y=py-c/2;
    p6x=px;
    p6y=py-c/2;
    p7x=px;
    p7y=py-a/2;
    cout<<fixed<<setprecision(12)<<xc(theta,p1x,p1y)<<"  "<<yc(theta,p1x,p1y)<<"\n";
    cout<<fixed<<setprecision(12)<<xc(theta,p2x,p2y)<<"  "<<yc(theta,p2x,p2y)<<"\n";
    cout<<fixed<<setprecision(12)<<xc(theta,p3x,p3y)<<"  "<<yc(theta,p3x,p3y)<<"\n";
    cout<<fixed<<setprecision(12)<<xc(theta,p4x,p4y)<<"  "<<yc(theta,p4x,p4y)<<"\n";
    cout<<fixed<<setprecision(12)<<xc(theta,p5x,p5y)<<"  "<<yc(theta,p5x,p5y)<<"\n";
    cout<<fixed<<setprecision(12)<<xc(theta,p6x,p6y)<<"  "<<yc(theta,p6x,p6y)<<"\n";
    cout<<fixed<<setprecision(12)<<xc(theta,p7x,p7y)<<"  "<<yc(theta,p7x,p7y)<<"\n";
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