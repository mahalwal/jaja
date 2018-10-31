#include <bits/stdc++.h>

using namespace std;

int main()
{
	int w, h;
	cin >> w >> h;
	int wt[w+1][h+1];
	for(int i=1; i<=w; i++)
		for(int j=1; j<=h; j++)
			cin >> wt[i][j];

	int dp[w+1][h+1];
	for(int i=0; i<=w; i++)
		for(int j=0; j<=h; j++)
			dp[i][j] = INT_MAX;

	for(int i=1; i<=h; i++)
		dp[w][i] = wt[w][i];
	for(int i=w; i>=2; i--)
	{
		for(int j=1; j<=h; j++)
		{
				if(w>1)
					dp[i-1][j] = min(dp[i-1][j], dp[i][j]+wt[i-1][j]);
				if(w>1 and h>1 and j>1)
					dp[i-1][j-1] = min(dp[i-1][j-1], dp[i][j]+wt[i-1][j-1]);
				if(w>1 and h>1 and j<h)
					dp[i-1][j+1] = min(dp[i-1][j+1], dp[i][j]+wt[i-1][j+1]);
		}
	}
	int ans = INT_MAX;
	for(int i=1; i<=h; i++)
		ans = min(ans, dp[1][i]);
	cout << ans << '\n';
}