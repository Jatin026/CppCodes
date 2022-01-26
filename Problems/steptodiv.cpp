#include<iostream>
using namespace std;
long long steps(long long a,long long b){
    long long count=0;
    if(a%b==0){
        return 0;
    }
    else{
    count=((a/b)+1)*b-a;
    return count;}
}
int main(){
    int t;
    cin>>t;
    int arr[t];
    int a,b;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        arr[i]=steps(a,b);
    }
    for(int i=0;i<t;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}