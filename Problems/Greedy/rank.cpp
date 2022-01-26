#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int d[3], s[3], ds = 0, ss = 0;
        for (int i = 0; i < 3; i++)
        {
            cin >> d[i];
            ds += d[i];
        }
        for (int i = 0; i < 3; i++)
        {
            cin >> s[i];
            ss += s[i];
        }
        if (ds > ss)
            cout << "dragon" << endl;
        else if (ss > ds)
            cout << "sloth" << endl;
        else
        {
            if (d[0] > s[0])
            {
                cout << "dragon" << endl;
            }
            else if (d[0] < s[0])
            {
                cout << "sloth" << endl;
            }
            else
            {
                if (d[1] > s[1])
                {
                    cout << "dragon" << endl;
                }
                else if (d[1] < s[1])
                {
                    cout << "sloth" << endl;
                }
                else
                {
                    if (d[2] > s[2])
                    {
                        cout << "dragon" << endl;
                    }
                    else if (d[2] < s[2])
                    {
                        cout << "sloth" << endl;
                    }
                    else
                        cout << "tie" << endl;
                }
            }
        }
    }
        return 0;
    }