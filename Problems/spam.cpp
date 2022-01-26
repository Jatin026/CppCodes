#include<iostream>
#include<vector>
using namespace std;
int main(){
    long long t;
    cin>>t; 
    vector<int> v ;
    long long k,x;
    for(int j=0;j<t;j++){
        cin>>k>>x;
        long long sum=0;
        if(k*k<=x){
            v.push_back(2*k-1);
        }

        else if((k/2)*k+1==x){
            v.push_back(k);
        }
        else{
            for(int i=1;i<=k;i++){
            sum+=i;
            if(sum>=x){
                v.push_back(i);
                break;
            }
        }
        if(sum<x){
            for(int i=k-1;i>0;i--){
                sum+=i;
                if(sum>=x){
                    v.push_back(2*k-i);
                    break;
            }
        }
        }
        
    }
    }
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}