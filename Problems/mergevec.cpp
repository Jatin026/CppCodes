#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n+1]={0};
    int cap1;
    cin>>cap1;
    int ele;
    for(int i=0;i<cap1;i++){
        cin>>ele;
        arr[ele]=1;
    }
    int cap2;
    cin>>cap2;
 
    for(int i=0;i<cap2;i++){
        cin>>ele;
        arr[ele]=1;
    }
    for(int i=1;i<=n;i++){
        if(arr[i]==0){
            cout<<"Oh, my keyboard!";
            exit(0);
        }
        }
    cout<<"I become the guy." ; 
    return 0;
}