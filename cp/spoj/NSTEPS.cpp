#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)

int main()
{
	fast_cin();
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int x, y;
		cin >> x >> y;

		if(x==y)
		{
			if(x&1)
				cout << 2*x-1 << '\n';
			else 
				cout << 2*x << '\n';
		}
		else if(y==x-2)
		{
			if(x%2==0)
				cout << 2*x-2 << '\n';
			else 
				cout << 2*x-3 << '\n';
		}
		else
		{
			cout << "No Number\n";
		}
	}
}