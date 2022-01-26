#include<iostream>
using namespace std;
const int N = 3e5;
int a[N];
int main(){
    int n,sum=0; cin>>n;
    string s; cin>>s;
    for (int i = 0; i < s.size(); i++)
    {
        a[i]=int(s[i])-48;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if(a[i]==0 && a[i+1]==1){
            a[i]=-1;
            a[i+1]=-1;
            i++;
        }
        else if(a[i]==1 && a[i+1]==0){
            a[i]=-1;
            a[i+1]=-1;
            i++;
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if(a[i]==1 || a[i]==0) sum++;
    }
    cout<<sum;
    return 0;
}