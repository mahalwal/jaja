#include <bits/stdc++.h>

using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
      cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
      const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

vector<int> g[10005];
int ret_first = true;

int bfs(int u, int n)
{
	bool vis[n+1];
	memset(vis, 0, sizeof(vis));
	
	queue<int> qu;
	qu.push(u);
	vis[u] = true;

	int len = 0;
	int path_len[n+1];
	path_len[u] = 0;

	while(!qu.empty())
	{
		int top = qu.front();
		qu.pop();
		for(auto i: g[top])
		{
			if(!vis[i] and i!=top)
			{
				qu.push(i);
				vis[i] = 1;
				path_len[i] = path_len[top] + 1;
			}
		}
	}

	int node = -1;
	int max_len = -1;
	for(int i=1; i<=n; i++)
	{
		if(path_len[i]>max_len)
		{
			node = i;
			max_len = path_len[i];
		}
	}
	if(ret_first==true)
	{
		ret_first = false;
		return node;
	}
	return max_len;
}



int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}


	int node = bfs(1, n);
	int len2 = bfs(node, n);

	cout << len2 << '\n';
}