#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	int t;
	cin >> t;

	while(t--)
	{

		ll n, i;
		cin >> n;
		int arr[n];
		for(i=0; i<n; i++)
			cin >> arr[i];

		i = n-1;
		while(i>0 and arr[i-1]>= arr[i])
			i--;
		if(i<=0)
		{
			cout << "-1\n";
			continue;
		}
		i--;
		bool found = false;
		for(ll ptr = n-1; ptr>i; ptr--)
		{
			if(arr[ptr]>arr[i])
			{
				swap(arr[ptr], arr[i]);
				found = true;
				break;
			}
		}

		for(ll ptr = 0; ptr<=i; ptr++)
		{
			cout << arr[ptr];
		}
		for(ll ptr = n-1; ptr>i; ptr--)
		{
			cout << arr[ptr];
		}
		cout<<'\n';
	}
}