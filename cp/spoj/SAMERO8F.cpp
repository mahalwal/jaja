#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)

int main()
{
	int t;
	cin >> t;
	while(t!=0)
	{
		cout << (t*(t+1)*(2*t+1))/6 << '\n';
		cin >> t;
	}
}