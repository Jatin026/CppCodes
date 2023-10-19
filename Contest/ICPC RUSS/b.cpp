#include<iostream>
#include<algorithm>
using namespace std;

long long min_in_array(int n, long long arr[]){
    
    long long  &min = *min_element(arr,arr+n );
    long long &max = *max_element(arr,arr+n );
    return min;
}

long long function(long long x, long long y,long long n, long long a[], long long b[]){
    
    long long c=0;
    for(int i=0;i<n;i++){
        long long p = a[i]-x;
        long long q = b[i]-y;
        if(p>=q){
            c+=p;
        }
        else{
            c+=q;
        }
    }
    return c;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        long long a[n],b[n];
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=0;j<n;j++){
            cin>>b[j];
        }
        long long x=min_in_array(n,a);long long y=min_in_array(n,b);
        cout<<function(x,y,n,a,b)<<endl;
    }
    return 0;
}