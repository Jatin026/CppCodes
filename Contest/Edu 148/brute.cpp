/**
 *    author:  tourist
 *    created: 12.05.2023 10:48:47       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  auto backup = a;
  while (q--) {
    int k;
    cin >> k;
    a = backup;
    for (int i = 0; i < n; i++) {
      if (k == 0) {
        break;
      }
      if (k % 2 == 0 && i == n - 1) {
        break;
      }
      a[i] += k;
      k -= 1;
    }
    assert(k % 2 == 0);
    k /= 2;
    sort(a.begin(), a.end());
    long long diff = 0;
    for (int i = 0; i < n; i++) {
      diff += a[i] - a[0];
    }
    int ans = a[0];
    if (k > diff) {
      k -= diff;
      ans -= (k + n - 1) / n;
    }
    cout << ans << ' ';
  }
  return 0;
}
