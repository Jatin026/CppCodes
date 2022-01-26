#include<iostream>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,count1{0},count2{0},sum=0;
        cin>>n;
        int arr[n];
        bool flag=false;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            if(arr[i]==1) count1++;
            else count2++;
        }
        if(sum%2==1) cout<<"NO"<<endl;
        else{
            for (int i = 0; i <=count1; i++)
            {
                for (int j = 0; j <= count2; j++)
                {
                    if(sum/2==i+2*j ) 
                    { 
                    flag=true;
                    break;
                    }
                }
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}