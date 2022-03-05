#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

int main(){
    ll n;
    cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n%2==0){
            n/=2;
        }
        else{
            n=n*3+1;
        }
        cout<<n<<" ";
    }
    return 0;
}