#include <bits/stdc++.h>
#define ll long long int
#define loop(i,o,n,step) for(auto i{o}; i < n; i += step)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int findS(int a, int b, vector<int> &As, vector<int> &Cs, vector<int> &Css, vector<vector<int>> &C){
    assert(a<0 || a >= n);
    if(b==-1){
    
        As[a] = findS(Cs[a], a, As, Cs, Css, C);
    }
    else{
        if(Cs[a] == b){
            if(C[a].size() == 1) return a;
            else{
                return findS(Css[a], a, As, Cs, Css, C);
            }

        }
        else {
            As[a] = findS(Cs[a], a, As,Cs,Css, C);
            return As[a];
        }
    }
}

int main(){
    FAST
    int n;
    cin >>n;
    vector<vector<int>> C(n);
    loop(i,0,n-1,1){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        C[u].push_back(v);
        C[v].push_back(u);
    }
    loop(i,0,n,1){
        sort(C[i].begin(),C[i].end());
    }
    vector<int> Cs(n,-1), Css(n, -1);
    loop(i,0,n,1){
        Cs[i] = C[i][0];
        if(C[i].size() > 1){
            Css[i] = C[i][1];
        }
    }
    vector<int> As(n,-1);
    loop(i,0,n,1){
        if(As[i] == -1) findS(i,-1, As,Cs, Css, C);
    }
    vector<int> Ab(n, -1);
    loop(i,0,n,1){
        reverse(C[i].begin(), C[i].end());
    }
    loop(i,0,n,1){
        Cs[i] = Css[i] = -1;
    }
    loop(i,0,n,1){
        Cs[i] = C[i][0];
        if(C[i].size() > 1){
            Css[i] = C[i][1];
        }
    }
    loop(i,0,n,1){
        if(Ab[i] == -1) findS(i,-1,Ab,Cs,Css, C);
    }
    loop(i,0,n,1){
        cout << Ab[i] + 1 << " " << As[i] + 1 << "\n";
    }
}