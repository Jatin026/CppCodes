#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
const int M = 1e9+7;
const int N =  1e6+3;
using namespace std;

ll BinExpItr(ll a , ll b){
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
ll mulo[N],mule[N];  // 1 3 4 5 6
int main(){
    FAST
    ll n;
    cin>>n;
    mule[1]=1;
    mule[0]=1;
    mulo[0]=1;
    for (int i = 1; i <= n; i++)
    {
        int ele;
        cin>>ele;
        if(i==1) mulo[i]=ele; 
        else if(i&1){
            mulo[i]=(mulo[i-2]*ele*1LL)%M;
            mule[i]=1;
        }
        else{
            mule[i]=(mule[i-2]*ele*1LL)%M;
            mulo[i]=1;  
        }
    }
    ll t;
    cin>>t;
    while(t--){
        ll l,r;
        ll ans;
        cin>>l>>r;
        if(l%2==0){
            if(l>1)
               ans = (((mule[2*((r-l)/2)+l])*(BinExpItr(mule[l-2],M-2)))%M)*((BinExpItr((mulo[2*((r-l-1)/2)+l+1]),M-2)*(mulo[l-1])*1LL)%M);
        }
        else{
            if(l>1)
               ans = (((mulo[2*((r-l)/2)+l]*BinExpItr((mulo[l-2]),M-2)))%M)*((BinExpItr((mule[2*((r-l-1)/2)+l+1]),M-2)*mule[l-1]*1LL)%M);
            else
                ans=((mulo[2*((r-l)/2)+l])%M)*((BinExpItr(mule[2*((r-l-1)/2)+l+1],M-2)*1LL)%M);
        }
        cout<<(ans%M)<<"\n";
    }
    return 0;
}