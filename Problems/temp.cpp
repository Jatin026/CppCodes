#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	int size;
    cin>>size;
    vector<int> v;
    int element;
    for(int i=0;i<size;i++){
        cin>>element;
        v.push_back(element);
    }
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=pow(v[i]/10,v[i]%10);
}
    cout<<sum;
    return 0;
}