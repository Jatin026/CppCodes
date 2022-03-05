#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    FAST
    int n,k;
    cin>>n>>k;
    int arr[n],cm=0,cp=0;
    for (int i = 0; i < n ; i++)
    {
        cin>>arr[i];
        if(arr[i]==1) cp++;
        else cm++;
    }
    while (k--)
    {
        int l,r;
        cin>>l>>r;
        if(((r-l+1)&1)==0){
            if((r-l+1)/2 <=min(cm,cp)){
                cout<<1<<"\n";
            }
            else{
                cout<<0<<"\n";
            }
        }
        else{
            cout<<0<<"\n";
        }
    }
    
    return 0;
}

 