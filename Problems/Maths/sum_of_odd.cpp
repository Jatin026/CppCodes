#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    if((n%2==0 && k%2==1)||(n%2==1 && k%2==0)) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}