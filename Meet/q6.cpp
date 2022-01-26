#include<bits/stdc++.h>
using namespace std;

int main(){
    float sum=1;
    for (int i = 1; i <= 100; i++)
    {
        sum+=i*10;
    }
    cout<<sum/101;
    return 0;
}