#include<bits/stdc++.h>
using namespace std;
long long int fac(int n){
    if (n<= 1) return 1;
    return n*fac(n-1);
}
set<string> arr;
void permute(string a, int l, int r )
{
    // Base case
    if (l == r){
        arr.insert(a);
        }
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
 
            // Swapping done
            swap(a[l], a[i]);
 
            // Recursion called
            permute(a, l+1, r);
 
            //backtrack
            swap(a[l], a[i]);
        }
    }
}
int main(){
    int n;
    cin>>n;
    long long int size=fac(2*n);
    string s="";
    for(int i=0 ; i< n ; i++){
        s+="01";
    }
    permute(s,0,2*n-1);
    auto it=arr.begin();
    while (it!=arr.end()){
        cout<<*it<<"\n";
        it++;
    }
    return 0;
}