#include<iostream>
#include<cmath>
using namespace std;

int main(){
    string s;
    cin>>s;
    unsigned long long product=1,new_product;
    for(int i=0;i<s.size()-12;i++){
        new_product=1;
        for(int j=i;j<i+13;j++){
            new_product*=(int(s[j])-48);
        }
        if(product<=new_product){
            product=new_product;
        }
    }
    cout<<product;
    return 0;
}