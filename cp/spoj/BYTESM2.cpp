#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int w, h;
		cin >> w >> h;
		int wt[w+1][h+1];
		for(int i=1; i<=w; i++)
			for(int j=1; j<=h; j++)
				cin >> wt[i][j];

		int dp[w+1][h+1];
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=h; i++)
			dp[w][i] = wt[w][i];
		for(int i=w; i>=2; i--)
		{
			for(int j=1; j<=h; j++)
			{
					if(w>1)
						dp[i-1][j] = max(dp[i-1][j], dp[i][j]+wt[i-1][j]);
					if(w>1 and h>1 and j>1)
						dp[i-1][j-1] = max(dp[i-1][j-1], dp[i][j]+wt[i-1][j-1]);
					if(w>1 and h>1 and j<h)
						dp[i-1][j+1] = max(dp[i-1][j+1], dp[i][j]+wt[i-1][j+1]);
			}
		}
		int ans = -1;
		for(int i=1; i<=h; i++)
			ans = max(ans, dp[1][i]);
		cout << ans << '\n';
	}
}