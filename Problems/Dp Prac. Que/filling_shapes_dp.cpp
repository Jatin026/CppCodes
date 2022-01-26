#include <bits/stdc++.h>
using namespace std;
long long int dp[61];
long long int count(int n)
{
    if (dp[n] != -1)
        return dp[n];
    if (n % 2 == 0)
    {
        dp[n] = 2 * count(n - 2);
        return dp[n];
    }
    return 0;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    dp[2] = 2;
    cout << count(n);
    return 0;
}