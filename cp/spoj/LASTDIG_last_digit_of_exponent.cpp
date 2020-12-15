#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll modexpo(ll a, ll b, ll n)
{
	ll ans = 1;
	while(b)
	{
		if(b%2)
			ans = (a*ans)%n;
		b /= 2;
		a = (a*a)%n;
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll a, b;
		cin >> a >> b;
		cout << modexpo(a, b, 10) <<'\n';
	}
}