#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
	int t;
	cin >> t;
	for(int i=0; i<t; i++)
	{
		ll n;
		cin >> n;
		cout << "Case " << i+1 << ": " << setprecision(5) << fixed << 0.25 + 4*n*n << '\n';
	}
}