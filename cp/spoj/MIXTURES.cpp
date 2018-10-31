#include <bits/stdc++.h>
using namespace std;

int matrix_chain_multiplication(int cost[], int n)
{
	int m[n][n], csum[n+1];
	memset(csum, 0, sizeof csum);
	for(int i=1; i<n; i++)
		m[i][i] = 0;
	for(int i=1; i<=n; i++)
	{
		csum[i] = (csum[i-1] + cost[i-1])%100;
	}
	for(int L=2; L<n; L++)
	{
		for(int i=1; i<n-L+1; i++)
		{
			int j = i+L-1;
			m[i][j] = INT_MAX;
			for(int k=i; k<=j-1; k++)
			{
				int q = m[i][k] + m[k+1][j] + (csum[k]-csum[i-1])*(csum[k+1]-csum[j-1]);
				if(q<m[i][j])
					m[i][j] = q;
			}
		}
	}
	return m[1][n-1];
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];
		cout << matrix_chain_multiplication(arr, n) << '\n';
	}
}