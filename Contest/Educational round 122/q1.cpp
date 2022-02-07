#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define end "\n"
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n%7==0) cout<<n<<end;  
    else{
        for (int i = (n/10)*10; i < (n/10)*10+10; i++)
        {
            if(i%7==0 && i!=0){
                cout<<i<<end;
                return;
            }
        }
    }
    
    
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