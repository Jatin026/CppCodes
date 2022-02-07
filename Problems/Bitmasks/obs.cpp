#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    FAST
     for (int i = 1; i <50; i++)
    {
        for(int j=i+1; j<51 ; j++){
        cout<<(i&j)<<"  "<<i<<"   "<<j<<"   "<<(i^j)<<'\n' ;
    }
    }
    return 0;
}