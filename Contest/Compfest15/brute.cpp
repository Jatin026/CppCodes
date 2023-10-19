#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=100005;
int n,q,m;
vector<pii>g[N];
int dp[N][2],frm[N][2];
int f[N];
vector<pii>vec[N];
vector<pii>Qry[N];
int ans[N];
int D;
void dfs1(int u,int fa){
    for(auto pr:g[u]){
        int v=pr.fi,w=pr.se;
        if(v==fa)continue;
        dfs1(v,u);
        if(dp[v][0]+w>dp[u][0]){
            dp[u][1]=dp[u][0];
            frm[u][1]=frm[u][0];
            dp[u][0]=dp[v][0]+w;
            frm[u][0]=v;
        }
        else if(dp[v][0]+w>dp[u][1]){
            dp[u][1]=dp[v][0]+w;
            frm[u][1]=v;
        }
    }
    D=max(D,dp[u][0]+dp[u][1]);
}
void dfs2(int u,int fa){
    for(auto pr:g[u]){
        int v=pr.fi,w=pr.se;
        if(v==fa)continue;
        f[v]=f[u]+w;
        if(frm[u][0]!=v){
            f[v]=max(f[v],dp[u][0]+w);
        }
        else{
            f[v]=max(f[v],dp[u][1]+w);
        }
        dfs2(v,u);
    }
    for(auto pr:g[u]){
        int v=pr.fi,w=pr.se;
        if(v==fa){
            vec[u].push_back({w,f[u]-w});
        }
        else{
            vec[u].push_back({w,dp[v][0]});
        }
    }
}
struct Line{
    int k,b;
}Ln[N];

vector<int>V;
int F(int i,int x){
    if(!i)return 0;
    return Ln[i].k*V[x-1]+Ln[i].b;
}
int getid(int x){
    return lower_bound(V.begin(),V.end(),x)-V.begin()+1;
}
struct lichao_tree{
    int tr[N<<2][2];
    void ins(int id,int l,int r,int o){
        int i=0;
        int mid=l+r>>1;
        if(tr[id][0]==0||F(o,mid)>F(tr[id][0],mid)){
            i=tr[id][0];
            tr[id][1]=tr[id][0];
            tr[id][0]=o;
        }
        else if(tr[id][1]==0||F(o,mid)>F(tr[id][1],mid)){
            i=o;
            tr[id][1]=o;
        }
        else{
            i=o;
        }
        if(l==r)return;
        if(!i)return;
        if(i==tr[id][1]||F(i,l)>min(F(tr[id][0],l),F(tr[id][1],l)))ins(id<<1,l,mid,i);
        if(i==tr[id][1]||F(i,r)>min(F(tr[id][0],r),F(tr[id][1],r)))ins(id<<1|1,mid+1,r,i);
    }
    pii qry(int id,int l,int r,int x){
        if(l==r){
            return {tr[id][0],tr[id][1]};
        }
        pii res={tr[id][0],tr[id][1]};
        int mid=l+r>>1;
        if(x<=mid){
            pii tmp=qry(id<<1,l,mid,x);
            if(res.fi==0||F(tmp.fi,x)>F(res.fi,x)){
                res.se=res.fi;
                res.fi=tmp.fi;
            }
            else if(res.se==0||F(tmp.fi,x)>F(res.se,x)){
                res.se=tmp.fi;
            }
            if(res.se==0||F(tmp.se,x)>F(res.se,x)){
                res.se=tmp.se;
            }
        }
        else{
            pii tmp=qry(id<<1|1,mid+1,r,x);
            if(res.fi==0||F(tmp.fi,x)>F(res.fi,x)){
                res.se=res.fi;
                res.fi=tmp.fi;
            }
            else if(res.se==0||F(tmp.fi,x)>F(res.se,x)){
                res.se=tmp.fi;
            }
            if(res.se==0||F(tmp.se,x)>F(res.se,x)){
                res.se=tmp.se;
            }
        }
        return res;
    }
}T;
void solve(int u){
    V.clear();
    for(auto pr:Qry[u]){
        V.push_back(pr.fi);
    }
    sort(V.begin(),V.end());V.erase(unique(V.begin(),V.end()),V.end());
    m=V.size();
    if(!m)return;
    for(int i=0;i<=m*4;i++)T.tr[i][0]=T.tr[i][1]=0;
    int tot=0;
    for(auto pr:vec[u]){
        Ln[++tot]={pr.fi,pr.se};
        T.ins(1,1,m,tot);
    }
    for(auto pr:Qry[u]){
        int v=getid(pr.fi);
        pii res=T.qry(1,1,m,v);
        ans[pr.se]=F(res.fi,v)+F(res.se,v);
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y,z;cin>>x>>y>>z;
        g[x].push_back({y,z});g[y].push_back({x,z});
    }
    dfs1(1,0);dfs2(1,0);
    cin>>q;
    for(int i=1;i<=q;i++){
        int x,k;cin>>x>>k;
        Qry[x].push_back({k,i});
    }
    for(int i=1;i<=n;i++){
        solve(i);
    }
    for(int i=1;i<=q;i++){
        ans[i]=max(ans[i],D);
        cout<<ans[i]<<"\n";
    }
    return 0;
}


