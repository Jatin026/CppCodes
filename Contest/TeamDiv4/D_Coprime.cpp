#include <bits/stdc++.h>
#define ll long long int
#define loop(i,o,n,step) for(auto i{o}; i < n; i += step)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool precomp[1001][1001]{};

int main(){
    FAST
    precomp[1][1] = 1;
    loop(i,1,1001,1){
        loop(j,i+1,1001,1){
            if(__gcd(i,j) == 1){
                precomp[i][j] = 1;
                precomp[j][i] = 1;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        int arr[1001]{};
        loop(i,0,n,1){
            int tmp;
            cin >> tmp;
            arr[tmp] = max(i + 1, arr[tmp]);
        }
        int mx{-1};
        if(arr[1] != 0)
            mx = 2 * arr[1];
        loop(i,0,1001,1){
            loop(j,i+1,1001,1){
                if(precomp[i][j] && arr[i] && arr[j]){
                    mx = max(mx, arr[i] + arr[j]);
                }
            }
        }
        cout << mx << "\n";
    }
}