#include<iostream>
#include<map>
using namespace std;

int main(){
    int t,ele,ans=0;
    cin>>t;
    map <int,int> m;
    for (int i = 0; i < t; i++)
    {
        cin>>ele;
        if(ele>0) m[ele]++;
        if(m[ele]==2) ans++;
        else if(m[ele]>2){ 
            cout<<-1;
            exit(0);
    }
    }
    cout<<ans;
    return 0;
}