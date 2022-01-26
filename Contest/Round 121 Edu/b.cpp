#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    bool flag = false;
    for (int i = s.size() - 1; i > 0; i--)
    {
        int z = (int(s[i]) + int(s[i - 1]) - 96);
        if (z >= 10)
        {
            cout << s.substr(0, i - 1);
            cout << '1';
            cout << z % 10;
            cout << s.substr(i + 1) << endl;
            flag = true;
            return;
        }
    }
    cout << char(int(s[0]) + int(s[1]) - '0');
    cout << s.substr(2) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
