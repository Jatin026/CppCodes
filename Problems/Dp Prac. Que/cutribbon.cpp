#include<bits/stdc++.h>
using namespace std;

int main(){
    float n,a,b,c;
    int count,max_count=INT_MIN;
    cin>>n>>a>>b>>c;
    for(int l=0 ; l<=a ; l++){
    for (int i = 0; i <= b ; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            if(i+j+l==n ){
                cout<<(l/n)<<" "<<(i/n)<<" "<<(j/n)<<" "<<endl;
                count=ceil(i/n)+ceil(l/n)+ceil(j/n);
                max_count=max(max_count,count);
                cout<<max_count<<endl;
        }
        }
        
    }
    }
    cout<<max_count;
    return 0;
}