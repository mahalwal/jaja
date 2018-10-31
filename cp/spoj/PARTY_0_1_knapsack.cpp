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


int knapsack(int fee[], int fun[], int n, int w)
{
	int knap[n+1][w+1];
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=w; j++)
		{
			if(i==0 or j==0)
				knap[i][j] = 0;
			else if(fee[i-1]<=j)
				knap[i][j] = max(fun[i-1] + knap[i-1][j-fee[i-1]], knap[i-1][j]);
			else
				knap[i][j] = knap[i-1][j];
		}
	}
	int lala = knap[n][w];
	int ret = lala;
	int sum = 0;

	for(int i=n; i>0 and ret>0; i--)
	{
		if(ret==knap[i-1][w])
			continue;
		else
		{
			sum = sum + fee[i-1];
			ret = ret-fun[i-1];
			w = w-fee[i-1];
		}

	}
	cout << sum << ' ';
	return lala;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int party_budget, n_parties;
	cin >> party_budget >> n_parties;

	while(party_budget and n_parties)
	{
		int fee[n_parties], fun[n_parties];
		for(int i=0; i<n_parties; i++)
			cin >> fee[i] >> fun[i];

		cout << knapsack(fee, fun, n_parties, party_budget) << '\n';

		cin >> party_budget >> n_parties;
	}
}