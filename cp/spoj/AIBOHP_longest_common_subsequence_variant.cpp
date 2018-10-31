#include <bits/stdc++.h>

using namespace std;

int lcs(string s, string t)
{
	int len1 = s.length();
	int len2 = t.length();
	int lcs[len1+1][len2+1];
	for(int i=0; i<=len1; i++)
	{
		for(int j=0; j<=len2; j++)
		{
			if(i==0 or j==0)
			{
				lcs[i][j] = 0;
				continue;
			}
			if(s[i-1]==t[j-1])
				lcs[i][j] = lcs[i-1][j-1] + 1;
			else 
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	}
	cerr << "LCS :"<< lcs[len1][len2] <<'\n';
	return lcs[len1][len2];
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		string t = s;
		reverse(t.begin(), t.end());
		cout << s.length() - lcs(s, t) << '\n';
	}
}