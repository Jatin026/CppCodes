#include <bits/stdc++.h>
#define ll long long int
#define loop(i,o,n,step) for(auto i{o}; i < n; i += step)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    FAST
    int n;
    cin >> n;
    vector<array<int, 3>> vec(n);
    loop(i,0,n,1){
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    }
    sort(vec.begin(), vec.end());
    int count{};
    loop(i,0,n,1){
        loop(j,i+1,n,1){
            if (vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2]){
                count++;
                break;
            }
        }
    }
    cout << count << "\n";
}