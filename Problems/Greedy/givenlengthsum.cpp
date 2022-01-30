#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
 
int main(){
    int l,sum;
    cin>>l>>sum;
    if( sum==0 && l==1) cout<<"0 0";
    else{int temp=sum;
    string s1="",s2;
    for (int i = 0; i < l; i++)
    {
        for (int j = 9; j >-1; --j)
        {
            if(j<=sum){
                s1+=to_string(j);
                sum-=j;
                break;
            }
        }
    }
    s2=s1;
    while(s2[0]!='1' && s2[l-1]!='9'&& l!=1){
        s2[0]--;
        s2[l-1]++;
    }
    if(l>2)
    {for (int i =1; i <= l/2; i++)
    {
        for (int j = l-1; j>=l/2 ; --j)
        {
             while(s2[i]!='0' && s2[j]!='9'){
                s2[i]--;
                s2[j]++;
    }  
    }
        }
    } 
    sum=temp;
    if((sum==0 && l>1)|| sum>l*9) cout<<"-1 -1";
    else cout<<s2<<" "<<s1;}
    return 0;
}