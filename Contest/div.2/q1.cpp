#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        pair<int , int> p[n];
        for (int i = 0; i < n; i++)
        {
            cin>>p[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            cin>>p[i].second;
        }
        sort(p,p+n);
        for (int i = 0; i < n; i++)
        {
            if(p[i].first<=k) k+=p[i].second;
            else break;
        }
        cout<<k<<endl;
    }
    return 0;
}