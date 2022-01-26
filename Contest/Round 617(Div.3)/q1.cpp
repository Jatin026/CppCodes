#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int size,count_o=0,count_e=0;
        cin>>size;
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            cin>>arr[i];
            if(arr[i]%2==1){
                count_o++;
            }
            else {
                count_e++;}
        }
        if(count_o%2==1 || count_e>0) {
        if (count_e!=size)
        {
         cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}