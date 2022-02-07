#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
using namespace std;
string f(ll n){
    vector <string> arr(n+1) ;
    arr[0]='\0';
    char m='a';
    for (int i = 1; i <=n; i++)
    {
        if(i<10) arr[i]=arr[i-1]+to_string(i)+arr[i-1];
        else{
            arr[i]=arr[i-1]+m+arr[i-1];
            m++;
        } 
    }
    return arr[n];
}
void solve(){
    ll n,k;
    cin>>n>>k;
    string s=bitset<50> (k).to_string();
    reverse(s.begin(),s.end());
    for (int i = 0; i < 51; i++)
    {
        if(s[i]=='1'){
            cout<<i+1;
            return;
        }
    }
    
}
int main(){
    FAST
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}