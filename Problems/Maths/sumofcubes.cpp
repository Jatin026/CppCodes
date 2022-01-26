#include <bits/stdc++.h>
using namespace std;
bool check_int(long long int x)
{
    long long int z = cbrtl(x);
    if (z*z*z == x && z!=0)
        return 1;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        bool flag = false;
        cin >> n;
        for (long long int i = 1; i <= int(cbrtl(n)); i++)
        {
            if (check_int((n -i*i*i)))
            {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}