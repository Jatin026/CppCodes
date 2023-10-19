#include <bits/stdc++.h>
#define ll long long int
#define loop(i,o,n,step) for(auto i{o}; i < n; i += step)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    loop(i, 0, 2 * n - 1, 1) s[i] = (s[i] == 'R' ? '0' : '1');
    int count{}, mx{};
    loop(i,0,n,1){
        count += s[i] - 48;
    }
    mx = count;
    loop(i,0,n-1,1){
        count -= s[i] - 48;
        count += s[i + n] - 48;
        mx = max(mx, count);
    }
    cout << mx;
}