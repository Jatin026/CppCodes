#include<bits/stdc++.h>
using namespace std;
ifstream in("lu.txt");
ofstream out("output.txt");
long long compute_hash(string s){
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] ) * p_pow[i]) % m;
    return h[n];
}
int main(){
    
    string input;
    int ways = 8 ;
    int no_blocks = 64;
    map<long long , long long > address[ways];
    int hit = 0 , miss = 0;
    while(in>>input){
        if(input[0] == '2'){
            // 1 -> Write
            long long hash_val = compute_hash(input.substr(1));
            bool flag = false;
            for(auto x : address){
                if(x.count(hash_val)){ 
                    hit++;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                miss++;
            }
        }
        else{
            long long hash_val = compute_hash(input.substr(1));
            bool flag = false;
            for(auto x : address){
                if(x.count(hash_val)){
                    hit++;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                miss++;
                for(auto &x : address){
                    if(x.size()<no_blocks){
                        x[hash_val] = 1;
                        break;
                    }
                }
            }
        }
    }
   
    cout << hit << " " << miss;
    return 0;
}