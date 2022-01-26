#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int l,r,k,ecount=0,ocount=0;
        cin>>l>>r>>k;
        if(l%2==1 && r%2==1){
            ecount=(r-l)/2;
            ocount=((r-l)/2 )+1;
        }
        else if(l%2==0 && r%2==0){
            ecount=((r-l)/2 )+1;
            ocount=(r-l)/2;
        }
        else{
            ecount=ocount=((r-l)/2 )+1;
        }
        if(l==r){
            if( l!=1 ){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else if(k==0){
            if(ocount==0){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            while(k>0 && ocount>0){
                ocount--;
                ecount++;
                k--;
            }
            if(ocount==0){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}