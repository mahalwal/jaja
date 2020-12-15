#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; cin>>arr[i++]);
	vector<int> lhs, rhs;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
				lhs.push_back(arr[i]*arr[j]+arr[k]);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
				if(arr[k])
					rhs.push_back(arr[k]*(arr[i]+arr[j]));
	sort(lhs.begin(), lhs.end());
	sort(rhs.begin(), rhs.end());

	int res = 0;
	for (int i = 0; i < lhs.size(); ++i)
	{
		int beg = lower_bound(rhs.begin(), rhs.end(), lhs[i]) - rhs.begin();
		int end = upper_bound(rhs.begin(), rhs.end(), lhs[i]) - rhs.begin();
		res = res + (end-beg);
		/*Alternate*/
		// auto tata = equal_range(rhs.begin(), rhs.end(), lhs[i]);
		// res = res + (tata.second - rhs.begin() - (tata.first - rhs.begin()));
	}
	cout << res << '\n';
}