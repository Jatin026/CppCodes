#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[27], count = 0;
    memset(arr, -1, sizeof(arr));
    string s1, s2;
    bool flag = true;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++)
    {

        if(s1[i]!=s2[i]) count++;
        if (arr[s1[i] - 96] == -1 && arr[s2[i] - 96] == -1)
        {
            arr[s1[i] - 96] = s2[i] - 96;
            arr[s2[i] - 96] = s1[i] - 96;
        }
        else
        {
            if (arr[s1[i] - 96] == s2[i] - 96 && arr[s2[i] - 96] == s1[i] - 96)
            {
                continue;
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        if (count == 0)
            cout << 0;
        else
        {
            int ans = 0;
            for (int i = 1; i <= 27; i++)
            {
                if (arr[i] != -1 && arr[i] != i)
                    ans++;
            }
            cout << ans / 2 << endl;
            for (int i = 0; i < 27; i++)
            {
                if (arr[i] != -1 && arr[i] != i)
                {
                    cout << char(i + 96) << " " << char(arr[i] + 96) << endl;
                    arr[arr[i]] = -1;
                }
            }
        }
    }
    else
        cout << -1;
    return 0;
}