#include <bits/stdc++.h>
#define ll long long int
#define loop(i,o,n,step) for(auto i{o}; i < n; i += step)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
 
int main(){
    FAST
    ll n, k;
    cin >> n >> k;
    ll arr[n+1];
    loop(i, 0, n, 1) cin >> arr[i];
    arr[n] = INT_MAX;
    sort(arr, arr + n + 1);
    ll curr{0}, val{arr[0]}, curr1{0}, val1{0};
    loop(i,0,n+1,1){
        if(arr[i] == val){
            curr++;
            continue;
        }
        if(k >= curr*(arr[i] - val)){
            k -= curr * (arr[i] - val);
            val = arr[i];
            curr++;
        }
        else{
            curr1 = k % curr;
            val += k / curr;
            val1 = val + 1;
            curr -= curr1;
            break;
        }
    }
    loop(i,0,curr,1){
        arr[i] = val;
    }
    loop(i,0,curr1,1){
        arr[i + curr] = val1;
    }
    ll sum{0};
    loop(i,0,n,1){
        sum += arr[i];
    }
    ll ans{0};
    loop(i,0,n,1){
        sum -= arr[i];
        ans += arr[i] * sum;
        ans %= 1000000007;
    }
    cout << ans;
}