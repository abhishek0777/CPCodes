/*
napsack
Given a set of  N   (N≤40)  integers each of them is at most  1012  determine the largest sum subset having sum less than or equal  S  ( S≤1018 )

If  N  was 20 we could've tried all possible subsets, but now  N  is 40 and  240  seems too much.

Lets split the numbers into two sets  (A,B) , first having the first  N2  numbers, second having the rest, now each of the two sets have at most 20 numbers.
Lets calculate subset sums for  A and store them in an array  X , and calculate subset sums for  B  and store them in an array  Y .

Now we sort the array  Y , and iterate over the elements of  X , for each element  x∈X , we can use binary search to find the largest element  y  in  Y  such that  x+y≤S
*/
// C++ program to demonstrate working of Meet in the 
// Middle algorithm for maximum subset sum problem. 
#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 
ll X[2000005],Y[2000005]; 

// Find all possible sum of elements of a[] and store 
// in x[] 
void calcsubarray(ll a[], ll x[], int n, int c) 
{ 
	for (int i=0; i<(1<<n); i++) 
	{ 
		ll s = 0; 
		for (int j=0; j<n; j++) 
			if (i & (1<<j)) 
				s += a[j+c]; 
		x[i] = s; 
	} 
} 

// Returns the maximum possible sum less or equal to S 
ll solveSubsetSum(ll a[], int n, ll S) 
{ 
	// Compute all subset sums of first and second 
	// halves 
	calcsubarray(a, X, n/2, 0); 
	calcsubarray(a, Y, n-n/2, n/2); 

	int size_X = 1<<(n/2); 
	int size_Y = 1<<(n-n/2); 

	// Sort Y (we need to do doing binary search in it) 
	sort(Y, Y+size_Y); 

	// To keep track of the maximum sum of a subset 
	// such that the maximum sum is less than S 
	ll max = 0; 

	// Traverse all elements of X and do Binary Search 
	// for a pair in Y with maximum sum less than S. 
	for (int i=0; i<size_X; i++) 
	{ 
		if (X[i] <= S) 
		{ 
			// lower_bound() returns the first address 
			// which has value greater than or equal to 
			// S-X[i]. 
			int p = lower_bound(Y, Y+size_Y, S-X[i]) - Y; 

			// If S-X[i] was not in array Y then decrease 
			// p by 1 
			if (p == size_Y || Y[p] != (S-X[i])) 
				p--; 

			if ((Y[p]+X[i]) > max) 
				max = Y[p]+X[i]; 
		} 
	} 
	return max; 
} 

// Driver code 
int main() 
{ 
	ll a[] = {3, 34, 4, 12, 5, 2}; 
	int n=sizeof(a)/sizeof(a[0]); 
	ll S = 10; 
	printf("Largest value smaller than or equal to given "
		"sum is %lld\n", solveSubsetSum(a,n,S)); 
	return 0; 
} 
