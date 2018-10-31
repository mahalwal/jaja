#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)

int main()
{
	int n;
	cin >> n;
	while(n!=0)
	{
		string str;
		cin >> str;
		char msg[200][n];
		int str_i = 0;
		int i;
		for(i=0; str_i < str.length(); i++)
		{
			for(int j=0; j<n; j++)
			{
				if(i%2==0)
				{
					msg[i][j] = str[str_i];
				}
				else
					msg[i][n-j-1] = str[str_i];
				str_i ++;
			}
		}

		int col_size = i;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<col_size; j++)
			{
				cout << msg[j][i];
			}
			// cout << '\n';
		}
		cout << '\n';
		cin >> n;
	}
}