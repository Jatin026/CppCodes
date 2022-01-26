#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
long long nearcube(long long x){
    long long n=floor(cbrt(x))-1;
    return(pow(n,3));
    
}
int main(){
    long long number;
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++ ){
        cin>>number;
        if(number==1 || number ==3 || number ==5 ){
            v.push_back("NO");
            continue;
        }
        else if( cbrt((number)/2)==round(cbrt((number)/2))){
            v.push_back("YES");
            continue;
    }
        else{
            for(int i=0;i<cbrt(number);i++){
                if(pow(i,3)+nearcube(number)==number){
                    v.push_back("YES");
                    continue;
            }
        }
    }
    v.push_back("NO");
    }
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<endl;
    }
    
    return 0;
}