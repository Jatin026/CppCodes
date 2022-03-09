#include <bits/stdc++.h>
#define ll long long int
#define loop(i,o,n,step) for(auto i{o}; i < n; i += step)
using namespace std;
 
//this part of sortbysec is from GFG
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b){
    return (a.second < b.second);
}
 
int main(){
    ifstream in("input.txt");
	// your code goes here
    ofstream out("output.txt");
    std::chrono::time_point<std::chrono::system_clock> start, end;
  
    start = std::chrono::system_clock::now();
    int t{0};
    in >> t;
    while(t--){
        int m, n;
        in >> m >> n;
        vector<pair<int,int>> one(0);
        map<int, int> two;
        loop(i,0,n,1){
            int tmp1, tmp2;
            in >> tmp1 >> tmp2;
            one.push_back(make_pair(tmp2, tmp1));
            two.insert(pair<int,int>(tmp1, i+1));
        }
        sort(one.begin(), one.end());
        //sort(two.begin(), two.end());
        loop(i, 2 * m, n, 1){
            one.pop_back();
        }
        sort(one.begin(), one.end(), sortbysec);
        ll sum{0};
        loop(i,0,2*m,1){
            sum += one.at(i).first;
        }
        out << sum << "\n";
        int a{0}, b{n-1};
        loop(i,0,m,1){
            
            out << two[one.at(i).second] << " " << two[one.at(2 * m - 1 - i).second] << "\n";
        }
        out << endl;
    }
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  
    std::cout << "finished computation at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
    return 0;
}