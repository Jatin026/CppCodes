#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int sum(int x, int ele[], int n){
    int sum=0;
    string s=bitset<15>(x).to_string();
    for (int i = 0; i < n; i++)
    {
        if(s[15-i-1]=='1') sum+=ele[i];
        else sum-=ele[i];
    }
    return sum;
}
int main(){
    FAST
    int n;
    cin>>n;
    int arr[(1<<n)],ele[n];
    for (int i = 0; i < n; i++)
    {
        cin>>ele[i];
    }
    for (int i = 0; i < (1<<n); i++)
    {
        arr[i]=sum(i,ele,n);
    }
    for (int i = 0; i < (1<<n); i++)
    {
        if(arr[i]%360==0){
            cout<<"YES";
            exit(0);
        }
    }
    cout<<"NO";
    return 0;
}