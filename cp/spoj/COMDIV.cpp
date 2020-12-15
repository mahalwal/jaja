#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)

int main()
{
	fast_cin(); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		int gcd = __gcd(a, b);
		int loop = sqrt(gcd);
		int count = 0;
		for(int i=1; i<=loop; i++)
		{
			if(gcd%i==0)
			{
				if(gcd/i==i)
					count++;
				else
					count+=2;
			}
		}
		cout << count << '\n';
	}
}