#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int size_s;
        string s;
        cin>>size_s;
        cin>>s;
        long long int sum=0,k;
        for (int i=0;i<s.size();i++)
        {
            k=int(s[i])-48;
            sum+=k*pow(2,size_s-i-1);
        }
        cout<<sum<<endl;
    }
    return 0;
}