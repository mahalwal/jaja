#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define fast_cin() ios_base::sync_with_stdio(false)
const int INF = 21474836;
const int MAX = 100002;
int n, m;
vector<int> D(MAX, INF);
vector<pair<int,int>> E[MAX];


int dijkstra(int start, int end)
{
	for(int i = 1; i <= n; i++) D[i] = INF;
	D[1] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

	q.push({0,1});

	while(!q.empty())
	{
		pair<int,int> p = q.top();
		q.pop();

		int u = p.second, dist = p.first;
		if(dist > D[u]) 
			continue;

		for(pair<int,int> pr : E[u])
		{
			int v = pr.first;
			int next_dist = dist + pr.second;

			if(next_dist < D[v])
			{
				D[v] = next_dist;
				q.push({next_dist, v});
			}
		}
		// if(u==end)
			// break;
	}
	return D[end];
}


int main()
{
	fast_cin();
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
	{
		fill(D.begin(), D.end(), 0);

		for(int i=0; i<=MAX; i++)
			E[i].clear();

		int a, b, w, cur, j,temp;
		vector<int> ans;

		cin>>n>>m;

		for(int i=0; i<m; i++)
		{
			cin>>a>>b>>w;
			E[a].push_back({b, w});
		}
		int start, end;
		cin >> start >> end;

		int ret = dijkstra(start, end);
		if(ret == INF)
		{
			cout<<"NO\n";
			continue;
		}
		cout << D[end] << '\n';
	}
}