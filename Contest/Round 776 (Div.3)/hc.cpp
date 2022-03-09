#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int, int> mp;
vector<int> x, w;
 
bool cmp(int a, int b)
{
    return mp[a] < mp[b];
}
int32_t main()
{
    ifstream in("input.txt");
    // your code goes here
    ofstream out("output.txt");
    std::chrono::time_point<std::chrono::system_clock> start, end;
    int t;
    in>> t;
    while (t--)
    {
        int n, m;
        in>> n >> m;
        x.clear();
        w.clear();
        w.assign(m, 0);
        x.assign(m, 0);
        mp.clear();
        vector<vector<int>> tmp;
        for (int i = 0; i < m; i++)
        {
            in>> x[i] >> w[i];
            tmp.push_back({w[i], i});
            mp[i] = x[i];
        }
        vector<int> temp;
        int ans = 0;

        sort(tmp.begin(), tmp.end());

        for (int i = 0; i < 2 * n; i++)
        {
            temp.push_back(tmp[i][1]);
        }
        for (int i = 0; i < 2 * n; i++)
        {
            ans += tmp[i][0];
        }
        out << ans << endl;
        sort(temp.begin(), temp.end(), cmp);

        for (int i = 0; i < n; i++)
        {
            out << temp[i] + 1 << " " << temp[2 * n - i - 1] + 1 << endl;
        }
        out << endl;
        
    }
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " <<fixed<< std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
    return 0;
}