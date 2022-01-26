#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    map<string,int> m;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        auto it=m.find(s);
        if(it==m.end()){
            cout<<"OK\n";
            m[s]++;
        }
        else{
            cout<<s<<m[s]<<endl;
            m[s]++;
        }
    }
    return 0;
}