#include<iostream>
using namespace std;
int divisor(int n){
    for (int i = 2; i< n/2; i++)
    {
        if(n%i==0) return i;
    }
    return n;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        while (k--)
        {
            if(n%2==0){
                n+=2*(k+1);
                break;
            }
            n=n+divisor(n); 
        }
        cout<<n<<endl;        
    }
    return 0;
}