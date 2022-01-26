#include <bits/stdc++.h>
using namespace std;
int divCount(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;
 
            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}
int isPrime(long long int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
void solve()
{
    int n;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    if (isPrime(arr[0]) == 0)
        cout << -1 << endl;
    else if(n==1){
       cout<< arr[0] * arr[n - 1];
    }
    else
    {
        if(divCount(arr[0] * arr[n - 1])!=n+2) cout<<-1<<endl;
        else cout<<(arr[0] * arr[n - 1])<<endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}