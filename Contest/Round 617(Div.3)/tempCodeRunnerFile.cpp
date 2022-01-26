#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int s, sum=1,k=1,rem;
        cin>>s;
        int temp=s;
        while(s >= 10) {
        sum += s / 10 * 10;
        s = s % 10 + s / 10;
    }
    sum += s;
        cout<<sum<<endl;
    }
    return 0;
}