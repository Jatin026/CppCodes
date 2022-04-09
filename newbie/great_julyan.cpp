#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define loop(i,o,n,s) for(auto i{o}; i < n; i+=s)
#define input_array(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
#define int long long
using namespace std;
// int N[1000+10];
    signed main() {
    FAST
    // for(int i=1;i<=1000;i++){
 
    // }
    int t ;
    cin>>t;
    // t=1 ;
    while(t--){
    int x;
    cin>>x;
    bool flag=0;
    for(int i=1;i*i*i<x;i++){
        for(int j=1;j*j*j <= (x);j++){
        if((x-i*i*i)==j*j*j){
            cout<<"yes\n";
            flag=1;
            break;
        }
        if(flag){
            break;
        }
    }
        if(flag) break;
    }
    if(!flag){
        cout<<"NO\n";
    }
    }
    return 0;
}