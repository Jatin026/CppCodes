#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main()
{
    int t, n, ele;
    cin >> t;
    string a[t];
    for (int k = 0; k < t; k++)
    {
        cin >> n;
        int area;
        bool jawab=true;
        vector<int> v;
        for (int i = 0; i < 4 * n; i++)
        {
            cin >> ele;
            v.push_back(ele);
        }
        sort(v.begin(), v.end());
         
        for (int i = 0; i < 4 * n ; i += 2)
        {
             if (v[i] != v[i + 1])
            {
                a[k] = "NO";
                jawab=false;
                break;
                 
            }
        }
        area = v[0] * v[4 * n - 1];
        if(jawab==1){
        for (int i = 2; i < 2*n; i += 2)
        {
            if (area != (v[i] * v[4 * n - i - 1]))
            {
                a[k] = "NO";
                jawab=false;
                break;
                  
            }
        
        }
        if(jawab==1) a[k] = "YES";
    }
    }
    for (int i = 0; i < t; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}