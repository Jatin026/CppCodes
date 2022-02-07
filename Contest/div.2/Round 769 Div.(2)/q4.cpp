#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int binary(int a, int b){
    int ans=0;
    while (a!=b)
    {
        if(b<a){
            return ans+a-b;
        }
        else{
            if(a|b-b<b-a){
                a=a|b; 
            }
            else a+=1;
        }
        ans++;
    }
    return ans;
}
int main(){
    FAST
    int t;
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<binary(a,b)<<"\n";
    }
    return 0;
}