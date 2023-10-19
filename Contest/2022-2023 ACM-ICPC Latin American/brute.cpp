#include <bits/stdc++.h>
using namespace std;
using ll  =  long long;
using ld  =  long double;
const int N = 2e5 + 5;


void MAIN(){
    ll n, k;
    cin >> n >> k;
    ll arr[n + 1];
    for (int i = 1; i <= n; i++) cin >> arr[i];

    ll prev[n + 1][30], nxt[n + 2][30];
    for (int bit = 0; bit <= 29; bit++) prev[0][bit] = 0, nxt[n + 1][bit] = n + 1;
    for (int i = 1; i <= n; i++) {
        for (int bit = 0; bit <= 29; bit++) {
            if (arr[i] & (1 << bit)) prev[i][bit] = i;
            else prev[i][bit] = prev[i - 1][bit];
        }
    }

    for (int i = n; i > 0; i--) {
        for (int bit = 0; bit <= 29; bit++) {
            if (arr[i] & (1 << bit)) nxt[i][bit] = i;
            else nxt[i][bit] = nxt[i + 1][bit];
        }
    }

    ll pref[n + 1], suf[n + 2];
    pref[0] = 0, suf[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        for (int bit = 0; bit <= 29; bit++) {
            if (pref[i] > k) break;
            pref[i] += prev[i][bit] * (1 << bit);
        }
    }
    for (int i = n; i > 0; i--) {
        suf[i] = suf[i + 1];
        for (int bit = 0; bit <= 29; bit++) {
            if (suf[i] > k) break;
            suf[i] += (n - nxt[i][bit] + 1) * (1 << bit);
        }
    }

    auto good = [&](int i, int j) -> bool {
        ll sum = pref[i - 1] + suf[j + 1];
        for (int bit = 0; bit <= 29; bit++) {
            if (2e18 / (1 << bit) <  prev[i - 1][bit] * (n - j)) return false;
            sum += prev[i - 1][bit] * (n - j) * (1 << bit);
            if (sum > k) return false;
            if (2e18 / (1 << bit) <  (i - 1 - prev[i - 1][bit]) * (n - nxt[j + 1][bit] + 1)) return false;
            sum += (i - 1 - prev[i - 1][bit]) * (n - nxt[j + 1][bit] + 1) * (1 << bit);
            if (sum > k) return false;
            cerr <<"sum -> " << sum << endl ;
        }
        cerr <<"sum -> " << sum << endl ;
        return sum <= k;
    };

    ll ans = 0;
    int ptr = 1;
    // for (int i = 1; i <= n; i++) {
    //     ptr = max(ptr, i);
    //     while (ptr <= n and !good(i, ptr)) ptr++;
    //     ans += n + 1 - ptr;
    //     cerr << ptr << endl;
    // }
    // cout << ans << '\n';
    cout << good(2,5);
}


int main(){
    ios:: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout<<fixed; cout<<setprecision(10);

    int t;
    cin >> t;
    while (t--) MAIN();
}