#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define pb push_back
#define ll long long
#define pii pair<int,int>
const int MAXN = 2e5+5;

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

long long trailing_zeros(ll n, ll k)
{

}

int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, k = 5, ans = 0;
		cin >> n;
		ll i = 1;

		while(n>=k)
		{
			// trace(n, k, ans);
			ans = ans + floor(n/k);
			k = pow(5, ++i);
		}

		cout << ans << '\n';
	}
}