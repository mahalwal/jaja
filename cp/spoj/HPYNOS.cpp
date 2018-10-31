#include <bits/stdc++.h>

using namespace std;

#define ll long long

map<ll, bool> mp;


ll solve(ll n)
{
	ll count = 1;
	while(1)
	{
		ll sum = 0;
		while(n)
		{
			sum = sum + pow(n%10, 2);
			n /= 10;
		}

		if(sum==1)
			return count;
		count++;
		n = sum;
		if(mp.find(sum)==mp.end())
			mp[sum] = 1;
		else
			return -1;
	}
}

int main()
{
	ll n;
	cin >> n;
	cout << solve(n) << '\n';
}