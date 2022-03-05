#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define all(s) s.begin(),s.end()
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
const int M = 1e9+7;
using namespace std;

ll BinExpItr(int a , int b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a)%M;
        }
        a=(a*a)%M;
        b>>=1;
    }
    return res;
}
void merge(int l ,int mid , int r, vector<int> &count , vector<pair<int,int>> &v)
{
vector<pair<int,int>> temp(r-l+1);
int i=l,j=mid+1;
int k=0;

            while( i<=mid && j<=r)
            {
                    if(v[i].first<=v[j].first)
                    {
                            // increasing order sorting 
                            temp[k++]=v[j++];
                    }
                    else
                    {
                            count[v[i].second]+= (r-j+1);
                            temp[k++]=v[i++];
                    }
            }
            
            while(i<=mid)
            {
                    temp[k++]=v[i++];
            }
            while(j<=r)
            {
                    temp[k++]=v[j++];
            }
           
            for(i=l;i<=r;i++)
            {
                    v[i]=temp[i-l];
            }
    }
    
    void mergesort(int l , int r, vector<int> &count , vector<pair<int,int>> &v)
    {
            if(l>=r)
            {
                    return ;
            }
            int mid=(l+r)/2;
            mergesort(l,mid,count , v);
            mergesort(mid+1,r,count , v);
            merge(l,mid,r,count , v);
    }
vector<int> countSmaller(vector<int>& nums) {
     int n=nums.size();
        vector<pair<int , int>> v(n);
       
        for(int i=0;i<n;i++)
        {
                v[i].first=nums[i];
                v[i].second =i;
        }
        vector<int> count(n,0);
        
        mergesort(0,n-1 , count ,v );
        return count;
        
}
void check(int j, vector<int> &v, vector<int> &m,int n){
    for (int i = j+1; i < n; i++)
    {
        if(v[j]>v[i])
            if(m[i]==0)
             m[i]=v[j];
    }
}
void solve(){
    int n;
    cin>>n;
    ll ans=0;
    set<int> s;
    vector<int> v(n),count,marked(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    marked[0]=v[0];
    for (int i = 0; i < n; i++)
    {
        if(marked[i]==0) check(i,v,marked,n);
    }
    for (int i = 0; i < n; i++)
    {
        s.insert(marked[i]==0 ? v[i] : marked[i]);
        cout<<marked[i]<<" ";
    }
    cout<<s.size()<<"\n";
    
}
int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}