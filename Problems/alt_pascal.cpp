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
    int n;
    cin>>n;
    int capacity;
     for(int i=0;i<n;i++){
        capacity=i+1;
        int r=0;
        for(int j=0;j<(2*n-1);j++){
            if(i+j>=n-1 && capacity>0 ){
                 cout<<comb(i,r)<<"   ";
                  capacity--;
                  r++;
            }
            else{
                  cout<<"  ";
             }
         }
        cout<<endl;
     }
    return 0;
}