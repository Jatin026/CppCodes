#include<bits/stdc++.h>
using namespace std;
double thetac(double kr, double kd, double Da, double La){
    return (log((kr/kd)*(1-(Da*(kr-kd))/(kd*La))))/(kr-kd);
}
int main(){
    double kr,kd,Da,La,v;
    cin>>kr>>kd>>Da>>La;
    double ans =thetac(kr,kd,Da,La);
    cout<<ans<<'\n'; // in units of k , ex-day^-1 of k then answer will be in days.
    cout<<ans*24*60*60<<"  Answer in Seconds\n";
    cout<<"Enter v : ";
    cin>>v;
    cout<<v*ans*24*60*60<<"   Critical Distance ";
    return 0;
}