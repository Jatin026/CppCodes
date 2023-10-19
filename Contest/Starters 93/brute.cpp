#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const string YES = "YES";
const string NO = "NO";

void solve() {
    int n;
    string s, ans;
    cin >> n >> s;
    if (n & 1) {
        cout << NO << endl;
        return;
    }
    //dp[index][balance] = possible or not?
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    function<int(int, int)> dfs = [&](int index, int balance)-> int {
        if (index >= n) {
            return (balance == 0 ? 1 : 0);
        }
        if (balance < 0) {
            return 0;
        }
        if (dp[index][balance] != -1) {
            return dp[index][balance];
        }
        int pick_open = 0, pick_closed = 0;
        int p = index;
        while (p + 1 < n && s[p] == s[p + 1]) {
            p++;
        }
        p++;

        pick_open = dfs(p, balance + p - index);
        if (pick_open > 0) {
            for (int j = 0; j < p - index; j++)
                ans += "(";
            dp[index][balance] = 1;
            return 1;
        }

        pick_closed = dfs(p, balance - (p - index));
        if (pick_closed > 0) {
            for (int j = 0; j < p - index; j++)
                ans += ")";
            dp[index][balance] = 1;
            return 1;
        }

        dp[index][balance] = 0;
        return 0;
    };

    int res = dfs(0, 0);
    reverse(ans.begin(), ans.end());

    if (res > 0) {
        cout << YES << endl;
        cout << ans << endl;
    } else {
        cout << NO << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}