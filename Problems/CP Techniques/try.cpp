#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int n,k,ele;
    cin>>n>>k;
    vector<vector<int>> v;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            cin>>ele;
            v[i].push_back(ele);
        }
    }
    return 0;
}