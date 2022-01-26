#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int sum_digit(int n){
    int sum=0;
    while (n>0)
    {
        sum+=n%10;
        n=n/10;
    }
    return sum;
}
int main(){
    // int a,b,c;
    // cin>>a>>b>>c;
    // vector<int> v;
    // for (int i = c; i <1e6 ; i++)
    // {
    //     if(sum_digit(i)==pow((i-c)/b,1.0/a)){
    //         v.push_back(i);
    //     }
    // }
    // cout<<v.size()<<endl;
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    int a=30,b=11;
    cout<<a/b--;
    return 0;
}