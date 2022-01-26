#include<iostream>
#include<vector>
using namespace std;

int main(){
//     vector<int> v;
//     v.push_back(1);
//     cout<<v[0];
// //     int j;
// //     for(j=1; j<5;j++){
// //         cout<<" ";
// //     }
// //     for(j=1; j<5;j++){
// //         cout<<j;
// //     }
// //     cout<<" sasfsdf "<<j;
    string s , rs;
    cin>>s;
    cin>>rs;
    string k;
    for(int i=0;i<s.size();i++){
        k+=s[s.size()-i-1];
    } 
    
    if(k==rs){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0; 
}