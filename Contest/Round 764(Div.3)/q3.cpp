#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool flag=true;
        int arr[n+1];
        int cnt[n+1];
        memset(cnt,0,sizeof(cnt));
        for (int i = 1; i <n+1; i++)
        {
            cin>>arr[i];
            while (arr[i]>n)
            {
                arr[i]=arr[i]/2;
            }
            if(cnt[arr[i]]==0) cnt[arr[i]]++;
            else{
                while(arr[i]!=1 && cnt[arr[i]]>0){
                    arr[i]=arr[i]/2;
                }
                cnt[arr[i]]++;
            }

        }
        for (int i = 1; i <n+1; i++)
        {
            if(cnt[i]==0 || cnt[i]>1){
                flag=false;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}