#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        if (n % 2 == 1)
            cout << "YES" << endl;
        else
        {
            while (n > 2)
            {
                n = n / 2;
                if (n % 2 == 1){
                    cout << "YES" << endl;
                    break;
                    }
            }
            if (n%2==0)
                cout << "NO" << endl;     
        }
    }
    return 0;
}