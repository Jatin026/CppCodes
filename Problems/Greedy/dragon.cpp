#include<bits/stdc++.h>
using namespace std;

int main(){
    int s,n;
    cin>>s>>n;
    bool flag=true;
    pair<int,int> p[n];
    for(int i=0 ; i<n ; i++){
        cin>>p[i].first>>p[i].second;
    }
    sort(p,p+n);
    for(int i=0 ; i<n ; i++){
        if(p[i].first>=s){
            flag=false;
            break;
        }
        s+=p[i].second;
    }    
    if(flag) cout<<"YES";
    else cout<<"NO";
    return 0;
}