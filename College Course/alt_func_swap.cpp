#include<bits/stdc++.h>
using namespace std;
void func(int a , int b , int c){
    int arr[3];
    arr[0]=b;
    arr[1]=c;
    arr[2]=a;
    for (int i = 0; i < 3; i++)
    {
        cout<<arr[i]<<"   ";
    } 
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    func(a,b,c);
    return 0;
}