#include<iostream>
using namespace std;

int main(){
    string s;
    int count_w=0,count=0;
    getline(cin,s);
    for (int i = 0; i < s.size(); i++)
    {
        if(islower(s[i])) s[i]=toupper(s[i]);
        else s[i]=tolower(s[i]);
        count+=1;
        if(s[i]!=' ') 
            count_w++;
        cout<<s[i];
    }
    cout<<endl;
    cout<<"Without space "<<count_w<<endl;
    cout<<"With Space "<<count<<endl;
    return 0;
}