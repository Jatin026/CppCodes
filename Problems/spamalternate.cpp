#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    long long t;
    cin>>t; 
    vector<int> v ;
    long long k,x;
    for(int j=0;j<t;j++){
        cin>>k>>x;
        long double n=0;
        if(k*k<=x){
            v.push_back(2*k-1);
        }
        else{
            if(k*(k+1)/2<=x){
                n=(pow(8*x+1,0.5)-1)/2.0;
                v.push_back(ceil(n));
            }
            else{
                n=(pow((k-1)*(k-1)+4*(k*k+k-2*x),0.5)+(k-1))/2.0;
                v.push_back(ceil(k+n));
            }
        }
         
    }
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}