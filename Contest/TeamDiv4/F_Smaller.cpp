#include <bits/stdc++.h>
#define ll long long int
#define loop(i,o,n,step) for(auto i{o}; i < n; i += step)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    FAST
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int s[26]{}, t[26]{};
        s[0]++;
        t[0]++;
        loop(i,0,n,1){
            int x,y;
            string str;
            cin >> x >> y >> str;
            if(x == 1){
                loop(j,0,str.size(),1){
                    s[str[i] - 97] += y;
                }
            }
            else{
                loop(j,0,str.size(),1){
                    t[str[i] - 97] += y;
                }
            }
            bool flag{1};
            loop(i,0,26,1){
                if(s[i] > t[i]){
                    flag =0;
                    break;
                }
            }
            if(flag) cout << "NO\n";
            else cout << "YES\n";
        }
    }

}