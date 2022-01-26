#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);    // Fast i/o
    cin.tie(NULL);
    int t,ele;
    cin>>t;
    vector<int> v;
    vector<int>:: iterator itr;
    for (int i = 0; i < t; i++)
    {
        cin>>ele;
        v.push_back(ele);
        // itr=find(v.begin(),v.end(),ele);
        // if(itr==v.end()) v.push_back(ele);
        // else{
        //     v.erase(itr);
        //     v.push_back(ele+1);
        //     }
    }
    sort(v.begin(),v.end());
    // itr=adjacent_find(v.begin(),v.end());
    // while (itr!=v.end())
    // {
    //     *(itr+1)=(*itr)+1;
    //     itr=v.erase(itr);
    //     itr=adjacent_find(v.begin(),v.end());
    // }
    itr=v.begin();
    for (int i = 0; i < t ; ++i)
    {
        cout<<*itr<<" the ele init   ";
        if(*itr==*(itr+1)){
            *(itr+1)+=1;
            v.erase(itr);
        }
        else itr++;
        cout<<*itr<<" the ele init   ";
    }
    
    cout<<v.size()<<endl;
    return 0;
}