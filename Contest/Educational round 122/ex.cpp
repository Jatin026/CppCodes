#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define end "\n"
using namespace std;

int main(){
    FAST
    int arr[5];
    for(int i=0 ;i < 5 ; i++){
        cin>>arr[i];
    }
    sortarr(arr);
    for(int i=0 ;i < 5 ; i++){
        cout<<arr[i]<<end;
    }
    return 0;
}