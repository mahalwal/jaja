#include <bits/stdc++.h>

using namespace std;

int totient(int n)
{
	float result = n;
	for(int p = 2; p*p<=n; p++)
	{
		if(n%p==0)
		{
			while(n%p==0)
				n = n/p;
			result *= (1.0-(1.0/(float(p))));
		}
	}
	if(n>1)
		result *= (1.0-(1.0/(float(n))));
	return (int)result;

}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << totient(n) << '\n';
	}
}