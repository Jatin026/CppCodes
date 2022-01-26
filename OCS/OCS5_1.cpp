#include <iostream>
#include<cmath>
using namespace std;
const int M = 1e9 + 7;
int main()
{
    string s;
    cin >> s;
    long long int ans = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'w' || s[i] == 'm')
        {
            cout << 0;
            exit(0);
        }
        else
        {
            long long int count = 1;
            int j = i;
            if (s[i] == 'u' || s[i] == 'n')
            {
                while (s[j] == s[j + 1])
                {
                    count++;
                    j++;
                }
                if (count > 1 && count%2==0)
                {
                    long long int k=1;
                    for (int i = 0; i < count/2; i++)
                    {
                        k=k*2%M;
                    }
                    count=-1+1.5*k;
                    ans = (ans * count) % M;
                }
                else if(count>1 && count%2==1){
                    long long int k=1;
                    for (int i = 0; i < count/2; i++)
                    {
                        k=k*2%M;
                    }
                    k=k-1;
                    count=(k)%M*(((count/2)+1))%M+1;//This is wrong
                    ans = (ans * count) % M;
                }
            }
            i = j;
        }
    }
    cout << ans % M << endl;
    return 0;
}