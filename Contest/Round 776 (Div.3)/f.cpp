#include <bits/stdc++.h>
using namespace std;
 
bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] < v2[1];
}
 
int main() {
     
  
  
     
	int t;cin>>t;
	for (int u=0;u<t;u++){
	    int n,m,c,d,sum=0;
	    cin>>n>>m;
	    vector<vector<int>> v;
	    for (int i=0;i<m;i++){
	        cin>>c>>d;
	        v.push_back({i+1,c,d});
	    }
	    for (int k=0;k<(m-2*n);k++){
	   	    int max=v[0][2],er=0;    
	        for (int i=0;i<v.size();i++){
	            if (v[i][2]>max){
	                max=v[i][2];er=i;
	            }
	        }
	        v.erase(v.begin()+er);
	    }
	    sort(v.begin(), v.end(), sortcol);
	    for (int i=0;i<2*n;i++) sum+=v[i][2];
	    cout<<sum<<endl;
	    for (int i=0;i<n;i++) cout<<v[i][0]<<" "<<v[2*n-i-1][0]<<endl;
	    cout<<endl;
	}   
     
	return 0;
}