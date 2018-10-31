#include <bits/stdc++.h>

using namespace std;

vector<int> g[MAXN];

bool bfs(int u, int n)
{
	bool vis[n+1];
	memset(vis, 0, sizeof(vis));
	queue<int> qu;
	qu.push(u);
	vis[u] = true;
	while(!qu.empty())
	{
		int top = qu.front();
		qu.pop();
		for(auto i: g[top])
		{
			if(!vis[i])
			{
				qu.push(i);
				vis[i] = 1;
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(!vis[i])
		{
			return 0;
		}
	}
	return 1;
}



int main()
{
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}

	if(n-1!=m)
	{
		cout << "NO\n";
		return 0;
	}

	if(bfs(1, n))
		cout << "YES\n";
	else
		cout << "NO\n";
}