#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int& x: b) cin >> x;
    vector<int> dp(3,-1e9);
    for (int i = 0; i < n; i++) {
        vector<int> new_dp(dp);
        new_dp[0] = max(dp[0], b[i]+i);
        new_dp[1] = max(dp[1], dp[0]+b[i]);
        new_dp[2] = max(dp[2], dp[1]+b[i]-i);
        swap(new_dp,dp);
    }
    cout << dp[2] << '\n';
  }
}
