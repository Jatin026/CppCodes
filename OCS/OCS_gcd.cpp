#include<iostream>
using namespace std;
long long find_hcf(long long a,long long b){
    a=a%b;
    if(a==0){
        return b;
    }
    b=b%a;
    if(b==0){
        return a;
    }
    else{
    return b;
    }
}
long long set_limit(long long l,long long h, long long hcf){
    if (hcf<l || hcf>h)
        {
            if(hcf<l){
                return -1;
                 
            }
            for(int i=2;i<hcf;i++){
                if(hcf%i==0){
                    int k=hcf/i;
                    if(k<h)
                    {
                        return(hcf/i);
                    }
                }
            }
            return -1;

        }
    else return (hcf);
}
int main(){
    long long a,b;
    cin>>a>>b;
    int t;
    cin>>t;
    long long arr[t];
    long long l,h;
    long long hcf=find_hcf(b,a); 
    for(int i=0;i<t;i++)
    {
        cin>>l>>h;
        arr[i]=set_limit(l,h,hcf);   
    }
    for(int i=0;i<t;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}