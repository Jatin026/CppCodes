#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <assert.h>
#include <sstream>
#include <iomanip>
#include <list>
#include <random>
#include <iterator>

using namespace std;

vector<int> a;
int n,k;



int solve(int l, int r)
{
    if (r-l+1 <= k+1)
        return r-l+1;


    int m = (l+r)/2;

    int ans = max(solve(l,m), solve(m+1,r));

    vector<vector<vector<int> > > dp(4,vector<vector<int> >(4, vector<int>(r-m+7)));

    for (int x=0;x<4;x++)
        for (int y=x;y<4;y++){
            dp[x][y][1+2] = !((x <= a[m+1]) && (a[m+1] <= y));
            dp[x][y][0+2] = 0;
        }

    for (int i=m+2;i<=r;i++)
    {
        for (int x=0;x<4;x++)
            for (int y=x;y<4;y++)
            {
                int j = i-m;
                if (a[i] < x || a[i] > y)
                    dp[x][y][j+2] = 1 + dp[x][y][j-1+2];
                else {
                    dp[x][y][j+2] = min(1 + dp[x][y][j-1+2], dp[x][a[i]][j-1+2]);
                }
            }
    }

    vector<vector<vector<int> > > dp2(4,vector<vector<int> >(4, vector<int>(m-l+7)));
    for (int x=0;x<4;x++){
        for (int y=x;y<4;y++){
            dp2[x][y][m-l+2] = !((x <= a[m]) && (a[m] <= y));
            dp2[x][y][m+1-l+2] = 0;
        }
    }

    for (int i=m;i>=l;i--)
    {
        for (int x=0;x<4;x++)
            for (int y=x;y<4;y++)
            {
                int j= i-l;
                if (a[i] < x || a[i] > y)
                    dp2[x][y][j+2] = 1 + dp2[x][y][j+1+2];
                else {
                    dp2[x][y][j+2] = min(1 + dp2[x][y][j+1+2], dp2[a[i]][y][j+1+2]);
                }
            }
    }

    for (int x=0;x<4;x++)
    {
        int L = l;
        int R = m;
        while(R <= r && L <= m+1)
        {

            if (dp2[0][x][L-l+2] + dp[x][3][R-m+2] > k)
                ++L;
            else {
                ans = max(ans, R-L+1);
                ++R;
            }
        }
    }

    return ans;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    a.resize(n);

    string s;
    cin >> s;
    for (int i=0;i<n;i++)
    {
        if (s[i] == '7') a[i] = 0;
        if (s[i] == '4') a[i] = 1;
        if (s[i] == '8') a[i] = 2;
        if (s[i] == '5') a[i] = 3;
    }

    cout << solve(0,n-1) << endl;

    return 0;
}


/*
5 5
4 1 5 4 5
2 2 4 5 1
1 0 4 3

*/