#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v={1 ,4 ,3 ,2 ,5 ,6 };
    rotate(v.begin(),v.begin()+4,v.end()-1);
    for (int i = 0; i < 6; i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}