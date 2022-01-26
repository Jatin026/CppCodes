#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    map<char,int> m;
    for (int i = 0; i < n; i++)
    {
        char ele;
        cin>>ele;
        m[ele]++;
    }
    for (char i = 'z'; i >='a'; --i)
    {
        if(k==0) break;
        else{
            while(m[i]--){
                if(k==0) break;
                cout<<i;
                k--;
            }
        }
    }
    return 0;
}