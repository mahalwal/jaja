#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MAXN = 1e6+1;

ll dp[MAXN];

ll solve(ll n)
{
	if(n < MAXN)
		return dp[n];
	return solve(n/2) + solve(n/3) + solve(n/4);
}

int main()
{
	ll n;
	for(int i=0; i<=11; i++)
		dp[i] = i;
	for(int i=12; i<=MAXN; i++)
		dp[i] = dp[int(i/2)] + dp[int(i/3)] + dp[int(i/4)];
	while(cin >> n)
	{
		cout << solve(n) << '\n';
	}
}