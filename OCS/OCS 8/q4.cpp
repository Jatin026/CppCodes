#include <bits/stdc++.h>
using namespace std;
// string circular(string s)
// {
//     return (s[s.size() - 1] + s.substr(0, s.size() - 1));  // right shift a string.
// }
// string ncirc(string s, int n)  // Right shift a string n times
// {   
//     string circ[s.size()];             // The pattern will repeat after the size of string.     
//     for (int i = 0; i < s.size(); i++)
//     {
//         circ[i] = s;
//         s = circular(s);
//     }
//     return circ[n % s.size()];
// }
int main()
{
    string s, z = "";
    cin >> s;
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        k=k%(r-l+1);
        // z = s.substr(l, r - l + 1);
        // z=z.substr(r-l+1-k)+z.substr(0,k+1);
        // s = s.substr(0, l) + z + s.substr(r+1);
        // s = s.substr(0, l)+ s.substr(r - k + 1, k) + s.substr(l, r - l + 1 - k)+ s.substr(r + 1);
        rotate(s.begin()+l-1,s.begin()+r-k,s.begin()+r);
    }
    cout << s;
    return 0;
}