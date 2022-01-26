#include <iostream>
using namespace std;

int main()
{
    int n, ele, cases = 0, sum = 0;
    cin >> n;
    int arr[n] = {0};
    for (int j = 0; j < n; j++)
    {
        cin >> ele;
        if (j == 0 && ele > 0)
        {
            arr[0] += ele;
        }
        else if (ele < 0)
            arr[cases] += ele;
        else
        {
            if(arr[cases]<0) {
            cases++;
            arr[cases] += ele;
            }
            else arr[cases] += ele;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (arr[j] <= 0)
        {
            sum += abs(arr[j]);
        }
    }
    cout << sum;
    return 0;
}