#include <bits/stdc++.h>

using namespace std;

#define int long long

const int n = 2;
const int mod = 1e9+7;

void multiply(int a[n][n], int b[n][n])
{
	int mul[n][n];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			mul[i][j] = 0;
			for(int k=0; k<n; k++)
				mul[i][j] = (mul[i][j] + (a[i][k]*b[k][j])%mod)%mod;
		}
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			a[i][j] = mul[i][j];
}

int power(int pow)
{
	int M[2][2] = {
		{1, 1},
		{1, 0}
	};
	int Res[2][2] = {
		{1, 1},
		{1, 0}
	};

	while(pow)
	{
		if(pow%2)
			multiply(Res, M);
		multiply(M, M);
		pow >>= 1;
	}

	return Res[0][0];
}


main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		if(a==0)
			cout << power(b)-1 << '\n';
		else
			cout << (power(b) - power(a-1)+mod)%mod << '\n';
	}
}