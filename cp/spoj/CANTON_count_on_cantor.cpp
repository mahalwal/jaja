#include <bits/stdc++.h>

using namespace std;

#define ll long long

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

const int MAXN = 1e5+1;

int main()
{
	ll a[MAXN];
	ll b[MAXN];
	ll i;
	a[0] = 0;
	b[0] = 0;
	for(i=1; i<=MAXN; i++)
		a[i] = 1+(i-1)*4;
	for(i=1; i<=MAXN; i++)
		b[i] = (i*(2+(i-1)*4))/2;
	for(i=1; i<=20; i++)
	{
		cerr << b[i]<<' ';
	}
	cerr<<'\n';

	ll ask; 
	cin >> ask;

	ll l = 1;
	ll r = MAXN;
	ll mid;

	while(l<=r)
	{
		mid = (l+r)/2;
		if(ask>b[mid])
		{
			trace("WHY");
			l = mid + 1;
		}
		else if(ask<b[mid])
		{
			trace("WHYNOT");
			r = mid - 1;
		}
		if(ask==b[mid])
		{
			trace("EQUALITY FOR ALL");
			break;
		}
		if(ask<=b[mid] and ask>b[mid-1])
			break;
		trace(ask, l, r, mid, b[mid]);
	}
	trace(mid, b[mid]);
	ll peek_a = a[mid]/2 + 1;
	trace(peek_a);

}