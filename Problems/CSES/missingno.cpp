#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
const int N=2e5+1;
int arr[N];
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int ele;
        cin>>ele;
        arr[ele]++;
    }
    for (int i = 1; i <=n ; i++)
    {
        if(arr[i]==0){
            cout<<i;
            break;
        }
    }
    
    return 0;
}