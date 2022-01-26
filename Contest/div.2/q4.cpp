#include<bits/stdc++.h>
using namespace std;
bool check(string s){
    string str=s;
    reverse(str.begin(), str.end());
    if(str==s) return 1;
    return 0;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,count=0;
        cin>>n;
        string k="";
        vector<string> v(n), ultav(n),ulta2(n),ulta3(n),s(n) ;
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
            k+=v[i];
            if((v[i]).size()==2){
                ulta2[i]=v[i];
            }
            else if((v[i]).size()==3){
                ulta3[i]=v[i];
            }
        }
        for (int i = 0; i < n-1; i++)
        {
            string k=(ulta2[i]+ulta2[i+1]).substr(0,3);
            reverse(k.begin(), k.end());
            s[i]=k;
        }
        for (int i = 0; i < n; i++)
        {
            string str=v[i];
            reverse(str.begin(), str.end());
            ultav[i]=str;
        }
        sort(v.begin(),v.end());
        sort(s.begin(),s.end());
        sort(ultav.begin(),ultav.end());
        sort(ulta3.begin(),ulta3.end());
        // for (int i = 0; i < n; i++)
        // {
        //     if(s[i]==ulta3[i]) count++;
        // }
        for (int i = 0; i < n; i++)
        {
            if(v[i]==ultav[i]) count++;
        }
        if(count>0 || check(k)==1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}