#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s;
        cin >> s;
        stack<char> st;
        int ans = 0 , flag = 0;
        for(auto x : s){    
            if(x == '(') {
                st.push(x);
                flag = 1;
            }
            else{
                st.pop();
                if(flag){
                    ans++;
                    flag = 0;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}