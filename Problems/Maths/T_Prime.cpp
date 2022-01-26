#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int ans[N];
bool isPrime(long long int n){
    if(n==1) return 0;
    for (long long int i = 2; i*i <=n; i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}
void Tprime(){
    for (int i = 2; i < N; i++)
    {
        if(isPrime(i)) ans[i]=1;
    } 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin>>t;
    Tprime();
    while (t--)
    {
        long long int n;
        cin>>n;
        long long int k=sqrt(n);
        if(k*k==n && ans[k]==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}