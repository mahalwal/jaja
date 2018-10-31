#include <bits/stdc++.h>

using namespace std;

bool sieve[10000+5];
vector<int> primes;
void gen_sieve(int n)
{
	memset(sieve, 1, sizeof(sieve));
	for(int p=2; p*p<=n; p++)
	{
		if(sieve[p])
		{
			for(int i=2*p; i<=n; i+=p)
				sieve[i]=0;
		}
	}
	for(int i=1000; i<=9999; i++)
		if(sieve[i])
			primes.push_back(i);
}

bool check(int t1, int t2)
{
	string a = to_string(t1);
	string b = to_string(t2);
	if(a[0]!=b[0] and a[1]==b[1] and a[2]==b[2] and a[3]==b[3])
		return 1;
	if(a[0]==b[0] and a[1]!=b[1] and a[2]==b[2] and a[3]==b[3])
		return 1;
	if(a[0]==b[0] and a[1]==b[1] and a[2]!=b[2] and a[3]==b[3])
		return 1;
	if(a[0]==b[0] and a[1]==b[1] and a[2]==b[2] and a[3]!=b[3])
		return 1;
	return 0;
}

int main()
{
	gen_sieve(10005);
	vector<int> graph[9999];

	for(auto i:primes)
	{
		for(auto j:primes)
		{
			if(i!=j)
			{
				if(check(i, j))
				{
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		queue<int> qu;
		int path=0;
		qu.push(a);
		bool found=0;
		int visited[10000];
		memset(visited, 0, sizeof(visited));
		visited[a]=1;
		int count=0;
		int dist[10000];
		for(int i=0; i<10000; i++)
			dist[i]=INT_MAX;
		dist[a]=0;
		while(!qu.empty())
		{
			int par = qu.front();
			qu.pop();
			for(int node:graph[par])
			{
				if(!visited[node])
				{
					visited[node]=true;
					qu.push(node);
					dist[node] = dist[par]+1;
				}
				if(node==b)
				{
					found=true;
					break;
				}
			}
			if(found)
				break;
		}
		if(dist[b]!=INT_MAX)
			cout << dist[b] << '\n';
		else cout<<"Impossible\n";
	}
}