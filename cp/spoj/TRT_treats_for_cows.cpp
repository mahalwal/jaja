#include <bits/stdc++.h>

using namespace std;

int n;
int profit[2001];
int cache[2001][2001];

int solve(int years, int bn, int en)
{
	if(bn>en)
		return 0;
	if(cache[bn][en]!=-1)
		return cache[bn][en];
	cache[bn][en] = max(solve(years+1, bn+1, en) + profit[bn]*years, 
			            solve(years+1, bn, en-1) + profit[en]*years);
	return cache[bn][en];
}

int main()
{
	cin >> n;
	memset(cache, -1, sizeof cache);
	for(int i=0; i<n; i++)
		cin >> profit[i];
	cout << solve(1, 0, n-1) <<'\n';
}