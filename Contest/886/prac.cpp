```cpp
#include <bits/stdc++.h>
#define ll long long int
#define loop(i,o,n,step) for(auto i{o}; i < n; i += step)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

const ll MOD = 1000000007;

int main(){
    ll n;
    cin >> n;
    ll arr[n]{}, brr[n]{}, crr[n]{};
    loop(i, 0, n, 1) cin >> arr[i];
    loop(i, 0, n, 1) cin >> brr[i];
    loop(i, 0, n, 1) cin >> crr[i];

    vector<array<ll, 3>> vec;
    loop(i, 0, n, 1) vec.push_back({arr[i], -crr[i], brr[i]});
    ll l{0}, r{INT_MAX}, best{0}, mncost{0};
    while(l <= r){
        ll mid = l + (r - l) / 2;
        ll cost{0}, moves{0};
        vector<ll> ind(n, 1);
        loop(i,0,n,1){
            if(vec[i][0] <= mid){
                moves += mid - vec[i][0];
                ind[i] = 0;
            }
        }
        vector<array<ll, 2>> rem;
        loop(i, 0, n, 1) if (ind[i]) rem.push_back({-vec[i][1], vec[i][0] - max(mid, vec[i][2])});
        sort(rem.begin(), rem.end());
        ll in{0};
        while(in < rem.size() && moves){
            ll del = min(moves, rem[in][1]);
            cost += (del * rem[in][0]) % MOD;
            moves -= del;
            in++;
        }
        if(moves){
            r = mid - 1;
        }
        else{
            best = mid;
            mncost = cost % MOD;
            l = mid + 1;
        }
    }
    cout << best << " " << mncost;
}```