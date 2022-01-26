#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool uni_year(string s){
    vector<int>v ={int(s[0]),int(s[1]),int(s[2]),int(s[3])};
    sort(v.begin(),v.end());
    for(int i=0;i<3;i++){
        if(v[i]==v[i+1]){
            return 0;
            exit(0);
        }
    }
    return 1;
}
int main(){
    int n;
    cin>>n;
    n++;
    string s=to_string(n);
    while(uni_year(s)==0){
        n++;
        s=to_string(n);
    }
    
    cout<<n;
    return 0;
}