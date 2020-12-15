#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define pii pair<int,int>
const int MAXN = 2e5+5;


ll rev(ll a)
{
	string rev_a = "";
	int first_zero = 1;
	while(a > 0)
	{
		ll rem = a % 10;
		a = a/10;
		if(first_zero and rem==0)
			continue;
		else
			first_zero = 0;
		rev_a += char(char(rem)+'0');
	}
	return (ll)stol(rev_a, 0, 10);
}

int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll a, b;
		cin >> a >> b;
		cout << rev(rev(a) + rev(b)) << '\n';
	}
}