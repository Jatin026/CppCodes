#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,r,c,ans=0,count=0;
        cin>>n>>m>>r>>c;
        char arr[n+1][m+1];
        for(int i=1; i<= n ;i++){
            for(int j=1 ; j<= m ; j++){
                cin>>arr[i][j];
                if(arr[i][j]=='W') count++;
            }
        }
        if(count==m*n) cout<<-1<<endl;
        else if(arr[r][c]=='B') cout<<0<<endl;
        else{
            int countbr=0,countbc=0;
            for(int j=1 ; j<= m ; j++){
                if(arr[r][j]=='B') countbc++;
            }
            for(int j=1 ; j<= n ; j++){
                if(arr[j][c]=='B') countbr++;
            }
            if(countbr>0 || countbc>0) cout<<1<<endl;
            else cout<<2<<endl;
        }

    }
    return 0;
}