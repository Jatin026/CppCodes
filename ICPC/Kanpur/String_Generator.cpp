#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define loop(i,o,n,step) for(auto i{o}; i < n; i += step)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

ld dist(ll ax, ll ay, ll bx, ll by){
    return sqrtl((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

int cil(ld a){
    if((int)a == a)
        return (int)a;
    return (int)a + 1;
}

int main(){
    int t;
    cin >> t;
    loop(tt,0,t,1){
        ll ax, ay, bx, by;
        cin >> bx >> by >> ax >> ay;
        ll dx, dy;
        ll n;
        cin >> dx >> dy >> n;
        vector<pair<ld, ll>> L;
        loop(i,0,n,1){
            ll x, y;
            ld r;
            cin >> x >> y >> r;
            ld d = dist(dx, dy, x, y);
            L.push_back({d + r, i});
            L.push_back({d - r, i});
        }
        sort(L.begin(), L.end());
        vector<pair<ld, ld>> V;
        ll ans{0};
        ld maxd{1.0*min(ax - dx, min(dx - bx, min(by - dy, dy - ay)))};
        if((*L.begin()).first >= 1.0){
            V.push_back({1, L[0].first});
        }
        ll curt = 1;
        int vis[n];
        vis[L[0].second] = 1;
        loop(i,1,L.size(),1){
            if(vis[L[i].second] == 1){
                curt -= 1;
            }
            else{
                curt += 1;
                vis[L[i].second] = 1;
            }
            if(curt == 0){
                if(i == L.size()-1){
                    V.push_back({L[i].first, maxd});
                }
                else{
                    V.push_back({L[i].first, L[i+1].first});
                }
            }
        }
        for(auto &v: V){
            if(v.first > maxd)
                break;
            ld a = min(maxd, v.second);
            ld b = min(maxd, v.first);
            ans += max((int)a - cil(b) + 1, 0);
        }
        cout << "Case " << tt + 1 << ": " << ans << "\n";
    }

}