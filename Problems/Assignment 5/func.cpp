#include<iostream>
using namespace std;
void pattern(){
    int n=10;
    int cap=1;
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 0; j < i; j++)
        {
           cout<<cap<<" ";
           cap++;
        }
        cout<<endl;
    }
}
bool kuch_chahiye(int n){
    if(n==1){
        return 1;
    }
    return 0;
}
float area(int l, int b){
    return l*b;
}
int main(){
    int x; cin>>x;
    pattern();
    return 0;
}