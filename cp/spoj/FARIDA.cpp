#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
	int t;
	cin >> t;
	for(int q=1; q<=t; q++)
	{
		ll n;
		cin >> n;
		ll arr[n+1];
		for(int i=1; i<=n; i++)
			cin >> arr[i];
		arr[0] = 0;
		for(int i=2; i<=n; i++)
			arr[i] = max(arr[i-1], arr[i]+arr[i-2]);
		cout << "Case " << q << ": " << arr[n] << '\n';
	}
}