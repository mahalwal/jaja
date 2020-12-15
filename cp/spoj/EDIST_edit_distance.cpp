#include <bits/stdc++.h>

using namespace std;
int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string a, b;
		cin >> a >> b;
		int lena = a.length(), lenb = b.length();
		int edit[lena+1][lenb+1];

		for(int i=0; i<=lena; i++)
			edit[i][0] = i;
		for(int i=0; i<=lenb; i++)
			edit[0][i] = i;
		for(int i=1; i<=lena; i++)
		{
			for(int j=1; j<=lenb; j++)
			{
				if(a[i-1]==b[j-1])
					edit[i][j] = edit[i-1][j-1];
				else edit[i][j] = min(edit[i-1][j-1], min(edit[i-1][j], edit[i][j-1])) + 1;
			}
		}
		cout << edit[lena][lenb] << '\n';
	}
}