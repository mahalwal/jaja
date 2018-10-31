#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	int lptr = 0, rptr = 0;
	long long curr_sum = 0, max_sum = 0;
	while(rptr!=n and lptr!=n)
	{
		if(arr[rptr]+curr_sum <= m)
		{
			curr_sum = curr_sum + arr[rptr];
			max_sum = max(max_sum, curr_sum);
			rptr++;
		}
		else
		{
			curr_sum -= arr[lptr];
			lptr++;
		}
	}
	cout << max_sum << '\n';
}