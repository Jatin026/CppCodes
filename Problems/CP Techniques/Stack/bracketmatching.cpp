#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack<char> st;
    bool flag=true;
    vector<char> op={'[','{','('},cl={']','}',')'};
    for (int i = 0; i < s.size(); i++)
    {
        auto it = find(op.begin(),op.end(),s[i]);
        if(it!=op.end()){
            st.push(s[i]);
        }
        else{
            if(st.empty()) flag=false;
            else{
            auto it1=find(cl.begin(),cl.end(),s[i]);
            if(it1-cl.begin()==(find(op.begin(),op.end(),st.top())-op.begin())){
               st.pop();
            }
            else flag=false;
            }
        }
    }
    if(st.size()!=0) flag=false;
    cout<<flag<<" ";
    return 0;
}