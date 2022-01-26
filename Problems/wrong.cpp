#include<iostream>
using namespace std;
bool add_algo(long long temp_a,long long b,long long temp_s){
    string s="";
    while (temp_a>0 || b>0)
    {
        s=to_string(temp_a%10+b%10)+s;
        temp_a=temp_a/10;
        b=b/10;
    }
    if(stoll(s)==temp_s){
        return 1;
    }
    else{
        return 0;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);    // Fast i/o
    cin.tie(NULL);
    int t;
    cin>>t;
    string arr[t];
    for(int i=0;i<t;i++){
    long long a,s,temp_a,temp_s;
    cin>>a>>s;
    string b="";
    temp_a=a;
    temp_s=s;
    bool flag=true;
    while(a>0 || s>0)
    {
        if((s%10-a%10)<0){
            if(s%100>=20){
                arr[i]="-1";
                flag=false;
                break;
            } 
            b=to_string(s%100-a%10)+b;
            s=s/100;
            a=a/10;
        }
        else {   
            b=to_string(-a%10+s%10)+b;
            a=a/10;
            s=s/10;
    }
    }
    if(flag){int c=add_algo(temp_a,stoll(b),temp_s);
    if(c==0){
        arr[i]="-1";
    }
    else{
        arr[i]=to_string(stoll(b));
    }
    }
    }
    for (int i = 0; i < t; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}