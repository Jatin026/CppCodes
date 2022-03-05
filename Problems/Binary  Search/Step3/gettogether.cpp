#include<bits/stdc++.h>
using namespace std;
struct range{
    long double a,b;
};
range intersection(long double a , long double b, long double c , long double d){
    range obj;
    obj.b=min(max(a,b),max(c,d));
    obj.a=max(min(a,b),min(c,d));
    return obj;
}
bool check(long double t,vector<int> &p,vector<int> &s){
    range obj;
    for (int i = 0; i < p.size(); i++)
    {
        if(i==0) obj=intersection(p[i]-t*s[i],p[i]+t*s[i],p[i+1]-t*s[i+1],p[i+1]+t*s[1+i]);
        else obj=intersection(obj.a,obj.b,p[i]-t*s[i],p[i]+t*s[i]);
        if(obj.a > obj.b) return 0;
    }
    return 1;
}
int main(){
    int n;
    cin>>n;
    vector<int> point(n),speed(n);
    for (int i = 0; i < n; i++)
    {
        cin>>point[i]>>speed[i];
    }
    long double t,l=0,r=LONG_LONG_MAX;
    while(l<=r){
        t=(l+r)/2;
        if(check(t,point,speed)){
            r=t-0.000001;
        }
        else{
            l=t+0.000001;
        }
    }
    cout<<fixed<<setprecision(12)<<r;
    return 0;
}