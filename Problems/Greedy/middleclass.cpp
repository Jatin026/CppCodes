#include <bits/stdc++.h>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;

int main()
{
    FAST int t;
    cin >> t;
    while (t--)
    {
        int n, x, ans = 0;
        cin >> n >> x;
        int arr[n];
        long long int sum[n + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + arr[i];
        }
        for (int i = 1; i < n + 1; i++)
        {
            if (((sum[n] - sum[i - 1]) * 1.0 / (n + 1 - i)) >= x)
            {
                ans = n + 1 - i;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}