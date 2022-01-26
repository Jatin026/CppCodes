#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int sum=0;
        string s;
        cin>>s;
        bool flag=true;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]=='>'){
                if(sum<0){
                    cout<<"?"<<endl;
                    flag=false;
                    break;
                }
                ++sum;
            }
            else if(s[i]=='<'){
                if(sum>0){
                    cout<<"?"<<endl;
                    flag=false;
                    break;
                }
                --sum;
            } 
        }
        if(sum>0 && flag) cout<<">"<<endl;
        else if( sum<0 && flag) cout<<"<"<<endl;
        else if(sum==0) cout<<"="<<endl;
    }
    return 0;
}