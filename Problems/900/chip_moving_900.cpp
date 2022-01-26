#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int arr[t],eve=0,odd=0;
    for (int i = 0; i < t; i++)
    {
        cin>>arr[i];
        if(arr[i]%2==0) eve++;
        else odd++;
    }
    if(odd>eve) cout<<eve;
    else cout<<odd;
    return 0;
}
