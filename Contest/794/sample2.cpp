// C++ program to count number of subsets with given GCDs
#include<bits/stdc++.h>
using namespace std;

// n is size of arr[] and m is sizeof gcd[]
void ccountSubsets(int arr[], int n, int gcd[], int m)
{
	// Map to store frequency of array elements
	unordered_map<int, int> freq;

	// Map to store number of subsets with given gcd
	unordered_map<int, int> subsets;

	// Initialize maximum element. Assumption: all array
	// elements are positive.
	int arrMax = 0;

	// Find maximum element in array and fill frequency
	// map.
	for (int i=0; i<n; i++)
	{
		arrMax = max(arrMax, arr[i]);
		freq[arr[i]]++;
	}

	// Run a loop from max element to 1 to find subsets
	// with all gcds
	for (int i=arrMax; i>=1; i--)
	{
		int sub = 0;
		int add = freq[i];

		// Run a loop for all multiples of i
		for (int j = 2; j*i <= arrMax; j++)
		{
			// Sum the frequencies of every element which
			// is a multiple of i
			add += freq[j*i];

			// Excluding those subsets which have gcd > i but
			// not i i.e. which have gcd as multiple of i in
			// the subset for ex: {2,3,4} considering i = 2 and
			// subset we need to exclude are those having gcd as 4
			sub += subsets[j*i];
		}
		
		// Number of subsets with GCD equal to 'i' is pow(2, add)
		// - 1 - sub
		subsets[i] = (1<<add) - 1 - sub;
	}

	 cout<<subsets[gcd[0]];
 
}

// Driver program
int main()
{
	int gcd[] = {1};
	int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
	int m = 1;
	ccountSubsets(arr, n, gcd, m);
	return 0;
}
