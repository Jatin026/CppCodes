#include <bits/stdc++.h>
#define ll long long int
#define loop(i,o,n,step) for(auto i{o}; i < n; i += step)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    FAST
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int arr[n][m]{};
        loop(i,0,n,1) loop(j,0,m,1) cin >> arr[i][j];
        int count{0};
        loop(i,0,n-1,1) loop(j,0,m-1,1){
            if(arr[i][j] && arr[i+1][j] && arr[i][j+1] && arr[i+1][j+1]){
                count++;
            }
        }
        cout << count << "\n";
    }
}