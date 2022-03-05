#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
const int M = 1e9+7;
using namespace std;

ll BinExpItr(int a , int b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a)%M;
        }
        a=(a*a)%M;
        b>>=1;
    }
    return res;
}
void solve(){
    int n;
    cin>>n;
    string s,k,z(2*n,'~');
    cin>>s>>k;
    sort(all(s));
    sort(all(k));
    reverse(all(k));
  
    int r=2*n-1, l=0;
    for (int i = 0; i < 2*n; i++)
    {
        auto it1=s.begin();
        auto it2=k.begin();
        if(i%2==0){
            if(*it1>=*it2){
            z[r]=*(s.end()-1);
            s.erase(s.end()-1);
            r--;
        }
            else{
            z[l]=*it1;
            s.erase(it1);
            l++; 
        }
        it1=s.begin();
        }
        else{
            if(*it1>=*it2){
                // cout<<*(s.end()-1)<<"\n";
                z[r]=*(k.end()-1);
                k.erase(k.end()-1);
                r--;
        }
            else{
            z[l]=*it2;
            k.erase(it2);
            l++; 
        }
        }
    }
    cout<<z<<"\n";
}
int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}