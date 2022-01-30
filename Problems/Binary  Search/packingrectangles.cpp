#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
long long int a,b,n;
bool f(long long int x){
    return (x/a)*(x/b)>=n;
}
int main(){
    FAST
    cin>>a>>b>>n;
    long long int mid,l=0,r=1;
    while(!f(r)) r*=2;
    while (l+1<r)
    {
        mid=(l+r)/2;
        if(f(mid)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    cout << r;
    return 0;
}