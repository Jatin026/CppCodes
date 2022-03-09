#include <bits/stdc++.h>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr, arr + sizeof(arr) / sizeof(int))
#define inputarr(arr, n)                    \
    for (int index = 0; index < n; index++) \
        cin >> arr[index];
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int odd{0}, even{0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] & 1 == 1)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    if (odd == n || even == n)
    {
        cout << -1 << endl;
    }
    else
    {
        int m{0};
        int dp_i[(int)4e5 + 7]{0};
        int dp_j[(int)4e5 + 7]{0};
        int ptri{0}, ptrj{0};
        if (arr[0] & 1 == 1)
        {
            int i{1};
            while (i < n)
            {
                if (i & 1 == 1)
                {
                    if (arr[i] & 1 == 0)
                    {
                        i++;
                    }
                    else
                    {
                        m++;
                        dp_i[ptri] = i;
                        dp_j[ptrj] = 0;
                        ptri++;
                        ptrj++;
                    }
                }
                else
                {
                    if (arr[i] & 1 == 1)
                    {
                        i++;
                    }
                    else
                    {
                        m++;
                        dp_i[ptri] = i;
                        dp_j[ptrj] = 0;
                        ptri++;
                        ptrj++;
                    }
                }
            }
        }
        else
        {
            int i{1};
            while (i < n)
            {
                if (i & 1 == 1)
                {
                    if (arr[i] & 1 == 1)
                    {
                        i++;
                    }
                    else
                    {
                        m++;
                        dp_i[ptri] = i;
                        dp_j[ptrj] = i - 1;
                        ptri++;
                        ptrj++;
                    }
                }
                else
                {
                    if (arr[i] & 1 == 0)
                    {
                        i++;
                    }
                    else
                    {
                        m++;
                        dp_i[ptri] = i;
                        dp_j[ptrj] = 0;
                        ptri++;
                        ptrj++;
                    }
                }
            }
        }
        cout << m << endl;
        for (int k = 0; k < m; k++)
        {
            cout << dp_i[k] << " " << dp_j[k] << endl;
        }
    }
}
int main()
{
    FAST int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}