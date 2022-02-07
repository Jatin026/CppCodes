#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define sortarr(arr) sort(arr,arr+sizeof(arr)/sizeof(ll))
#define inputarr(arr,n) for(ll index=0; index < n ; index++) cin>>arr[index];
using namespace std;
ll *st; 
/*  A recursive function to get gcd of given
    range of array indexes. The following are parameters for
    this function.
  
    st    --> Poller to segment tree
    si --> Index of current node in the segment tree. Initially
               0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment
                 represented by current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
ll findGcd(ll ss, ll se, ll qs, ll qe, ll si)
{
    if (ss>qe || se < qs)
        return 0;
    if (qs<=ss && qe>=se)
        return st[si];
    ll mid = ss+(se-ss)/2;
    return __gcd(findGcd(ss, mid, qs, qe, si*2+1),
               findGcd(mid+1, se, qs, qe, si*2+2));
}
  
//Finding The gcd of given Range
ll findRangeGcd(ll ss, ll se, ll arr[],ll n)
{
    if(ss==se) return arr[se];
    if (ss<0 || se > n-1 || ss>se)
    {
        return -1;
    }
    return findGcd(0, n-1, ss, se, 0);
}
  
// A recursive function that constructs Segment Tree for
// array[ss..se]. si is index of current node in segment
// tree st
ll constructST(ll arr[], ll ss, ll se, ll si)
{
    if (ss==se)
    {
        st[si] = arr[ss];
        return st[si];
    }
    ll mid = ss+(se-ss)/2;
    st[si] = __gcd(constructST(arr, ss, mid, si*2+1),
                 constructST(arr, mid+1, se, si*2+2));
    return st[si];
}
  
/* Function to construct segment tree from given array.
   This function allocates memory for segment tree and
   calls constructSTUtil() to fill the allocated memory */
ll *constructSegmentTree(ll arr[], ll n)
{
   ll height = (ll)(ceil(log2(n)));
   ll size = 2*(ll)pow(2, height)-1;
   st = new ll[size];
   constructST(arr, 0, n-1, 0);
   return st;
}
void solve(){
    ll n;
    cin>>n;
    ll arr[n]={0}; 
    for (ll i = 0; i < n ; i++)
    {
        cin>>arr[i];
    }
    constructSegmentTree(arr, n);
    ll l=0 , ans=LONG_LONG_MAX ;
    for (ll r = 0; r <  n ; r++)
    {
        while(findRangeGcd(l, r, arr, n) ==1 ){
            ans=min(ans,r-l+1); 
            l++;
        }
    }
    if(ans==LONG_LONG_MAX) cout<<-1;
    else cout<<ans;
}
int main(){
    FAST
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}