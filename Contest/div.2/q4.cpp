#include<bits/stdc++.h>
using namespace std;
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = -1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,count=0;
        cin>>n;
        string k="";
        int v[n];
        vector<int> l;
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
            k+=v[i];
             
        }
        l=manacher_odd(k);
        if(l.size()>0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}