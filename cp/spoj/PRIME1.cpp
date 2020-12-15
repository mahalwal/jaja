#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define pii pair<int,int>
const ll MAXN = 1e9+5;

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


void primes(bool prime[], ll limit)
{
	memset(prime, true, sizeof prime);
	for(ll p = 2; p*p<=limit; p++)
	{
		if(prime[p])
		{
			for(ll i = 2*p; i<=limit; i+=p)
			{
				prime[i] = 0;
			}
		}
	}
}

int main()
{
	fast_cin();

	bool prime[100005];
	ll m, n;
	cin >> m >> n;

	ll limit =  floor(sqrt((double)n));
	primes(prime, limit);

	bool segment[n-m+1];
	memset(segment, 1, sizeof segment);

	for(ll i=2; i<=limit; i++)
	{
		if(prime[i])
		{
			// trace(i);
			ll smaller = m/i;
			smaller = smaller * i;
			if(smaller < m)
				smaller += i;
			for(; smaller<=n; smaller += i)
					segment[smaller-m] = false;
		}
	}
	for(int i=2; i<=limit; i++)
	{
		if(i>=m and i<=n and prime[i])
			cout << i << ' ';
	}

	for(int i=0; i<n-m+1; i++)
	{
		if(segment[i])
			cout << i+m << ' ';
	}

	cout<<'\n';
}