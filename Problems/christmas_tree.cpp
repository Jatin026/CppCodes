#include<iostream>
using namespace std;
int fac(int n){
    if (n==1){
        return 1;
    }
    else if(n==0){
        return 1;
    }
    else{
        return(n*fac(n-1));
    } 
    }
int comb(int n, int r){
    return(fac(n)/(fac(r)*fac(n-r)));
}
int main(){
    int t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        for (int i = 0; i <n; i++)
        {
            for (int j = 0; j <=i; j++)
            {
                cout<<comb(i,j)<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
    return 0;
}