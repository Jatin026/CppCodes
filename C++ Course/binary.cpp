#include<iostream>
#include<bitset>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<bitset <8> (i).to_string()<<endl;
    }
    return 0;
}