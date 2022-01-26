#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main() {
    int q;
    cin>>q;
    set<int> s;
    for (int i=0; i<q; i++) {
        int j;
        int k;
        cin>>j>>k;
        if (j==1){
            s.insert(k);
        }
        else if (j==2){
            s.erase(k);
        }
        else if (j==3){
            set<int> :: iterator itr =s.find(k);
            if( itr==s.end()){
                cout<<"No"<<endl;
                
            }
            else{
                cout<<"Yes"<<endl;
            }
        }
    }  
    return 0;
}



