#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[27],distinct=0;
    memset(arr,0,sizeof(arr));  // sets every element of arr 0.
    string s;
    cin>>s;
    for (int i = 0; i < s.size(); i++)
    {   
        arr[s[i]-96]++;
    }
    for (int i = 0; i <= 26; i++)
    {   
        if(arr[i]>0) distinct++;
    }
    if(distinct%2==0)cout<<"CHAT WITH HER!"<<endl;
    else {
        cout<<"IGNORE HIM!"<<endl;
    
        
    }
    return 0;
}