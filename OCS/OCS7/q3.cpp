#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,index=1;
    cin>>n;
    bool flag=false;
    string s;
    cin>>s;
    int arr[n];
    for(int i=0 ; i< n ; ++i){
        cin>>arr[i];
    }
    for(int i=0 ; i < n ; i++){
        if(index>n || index<1){
            flag=true;
            break;
        }
        if(s[index-1]=='<'){
            index-=arr[index-1];
        }
        else{
            index+=arr[index-1];
        }
    }
    if(index>n || index<1 || flag ){
        cout<<"FINITE";
    }
    else{
        cout<<"INFINITE";
    }
    return 0;
}