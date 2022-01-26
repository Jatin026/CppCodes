#include<iostream>
using namespace std;

int main(){
    int n,m,ans=0,count;
    cin>>n>>m;
    bool flag=false;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }
    //Left Right Wala
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j]==1) flag=true;  
        }
        if(flag){
            if(arr[i][0]==0 && arr[i][m-1]==0) ans+=m;
            else ans+=m-1;
            }
        flag=false;
    }  
    // for(int i=0;i<n-1;i++){
    //     for (int j = 0; j < m; j++)
    //     {
    //         if(arr[i][j]==0 && arr[i+1][j]==1){ 
    //             ans+=1;
    //             cout<<"Ek  niche wala "<<i+1<<j+1<<endl;
    //             }
            
    //     }  
    // }
    // for(int i=1;i<n;i++){
    //     for (int j = 0; j < m; j++)
    //     {
    //         if(arr[i][j]==0 && arr[i-1][j]==1) {
    //             ans+=1;
    //             cout<<"Ek  upar wala "<<i+1<<j+1<<endl;}
            
    //     }  
    // }
    int column=0;
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++)
        {
            if(arr[j][i]==1) flag=true;  
        }
        if(flag){ 
        if(arr[0][column]==0 && arr[n-1][column]==0)    ans+=n-2;
        else ans+=n ;
        }
        flag=false;
        column++;
    }  
    cout<<ans;
    return 0;
}