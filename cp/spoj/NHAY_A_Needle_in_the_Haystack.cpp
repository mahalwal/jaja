#include <bits/stdc++.h>

using namespace std;

void computeLPS(string pat, int M, int lps[])
{
	int len = 0;
	lps[0] = 0;
	int i=1;
	while(i<M)
	{
		if(pat[i]==pat[len])
			lps[i++] = ++len;
		else
		{
			if(len!=0)
				len = lps[len-1];
			else
				lps[i++] = 0;
		}
	}
}


vector<int> kmp_string_match(string text, string pat)
{
	vector<int> ans;
	int M = pat.length();
	int N = text.length();
	int lps[M];
	computeLPS(pat, M, lps);

	int i=0, j=0;
	while(i<N)
	{
		if(pat[j]==text[i])
		{
			i++;
			j++;
		}
		if(j==M)
		{
			ans.push_back(i-j);
			j = lps[j-1];
		}
		else if(i<N and pat[j]!=text[i])
		{
			if(j!=0)
				j = lps[j-1];
			else 
				i++;
		}
	}
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m;
	while(cin>>m)
	{
		string pat;
		cin >> pat;
		string text;
		cin >> text;
		int a = pat.length();
		int b = text.length();
		if(a>b)
		{
			cout << '\n';
			continue;
		}
		vector<int> ans = kmp_string_match(text, pat);
		for(auto i: ans)
			cout << i << '\n';
		cout << '\n';
	}
}