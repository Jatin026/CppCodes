#include <bits/stdc++.h>
using namespace std;
long long int cube(long long int x) {
    return x*x*x;
}
bool binary(long long int x){
    int l=1,r=10000;
    while (l<=r)
    {
        long long z=cube(l)+cube(r);
        if(z==x){
            return 1;
        }
        else if(z>x){
            r--;
        }
        else{
            l++;
        }
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        bool flag = binary(n);
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}