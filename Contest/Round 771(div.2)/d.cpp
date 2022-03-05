#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    pair<int, int> p[n];
    for(int i= 0;  i< n ; i++){
        cin>>p[i].first>>p[i].second;
    }
    sort(p,p+n);
    for (int i = 0; i < n-1; i++)
    {
        if(p[n-1].second<p[i].second){
            cout<<"Happy Alex";
            return 0;
        }
    }
    cout<<"Poor Alex";
    return 0;
}