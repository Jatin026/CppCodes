#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(int))
#define inputarr(arr,n) for(int index=0; index < n ; index++) cin>>arr[index];
using namespace std;
long double calculate_angle(int n, int i, int j, int k)
{
    // Initialize x and y
    long double x, y;
 
    // Calculate the number of vertices
    // between i and j, j and k
    if (i < j)
        x = j - i;
    else
        x = j + n - i;
    if (j < k)
        y = k - j;
    else
        y = k + n - j;
 
    // Calculate the angle subtended
    // at the circumference
    double ang1 = (180 * x) / n;
    double ang2 = (180 * y) / n;
 
    // Angle subtended at j can be found
    // using the fact that the sum of angles
    // of a triangle is equal to 180 degrees
    double ans = 180 - ang1 - ang2;
    return ans;
}
void solve(){
    ll n,a,ans;
    cin>>n>>a;
    long double arr[n+1],val=INT_MAX;
    for (int i = 3; i <=n ; i++)
    {
        arr[i]=abs(calculate_angle(n,1,2,i)-a);
    }
    for (int i = 3; i <=n ; i++)
    {
        if(arr[i]<val){
            ans=i;
            val=arr[i];
        }
    }
    cout<<"1 2 "<<ans;
}
int main(){
    FAST
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
