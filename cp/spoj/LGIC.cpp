#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, ans = 1;
	cin >> n;
	for(int i=1; i<=n; i++)
		ans = ans * i;
	cout << (ans = ans + pow(2, n) - n);
}