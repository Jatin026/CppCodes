#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    while (q--)
    {
        int colour;
        cin >> colour;
        auto it = find(v.begin(), v.end(), colour);
        cout << (int)(it - v.begin() + 1) << " ";
        // v.erase(it);
        // v.insert(v.begin(), colour);
        rotate(v.begin(), v.begin() + (int)(it - v.begin()), v.begin() + (int)(it - v.begin() + 1));
    }
    return 0;
}