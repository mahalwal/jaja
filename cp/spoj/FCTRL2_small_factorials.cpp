#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)

string sum(string a, string b)
{
	int len1, len2;
	string s1, s2;
	if(a.length() <= b.length())
	{
		s1 = b; len1 = s1.length();
		s2 = a; len2 = s2.length();
	}
	else if(a.length() > b.length())
	{
		s1 = a; len1 = s1.length();
		s2 = b; len2 = s2.length();
	}
	string ans = "";

	int carry = 0;
	int n1, n2;

	for(int i=len1-1, j = len2-1; i>=0; i--, j--)
	{
		if(j<0)
			n2 = 0;
		else 
			n2 = s2[j]-'0';
		n1 = s1[i]-'0';
		int n3 = n1+n2+carry;
		int rem = n3%10;
		carry = n3/10;
		ans = ans + to_string(rem);
	}
	if(carry>0)
		ans = ans + to_string(carry);
	reverse(ans.begin(), ans.end());
	return ans;

}
string multiply(string a, string b)
{
	int len1, len2;
	string s1, s2;
	if(a.length() <= b.length())
	{
		s1 = b; len1 = s1.length();
		s2 = a; len2 = s2.length();
	}
	else if(a.length() > b.length())
	{
		s1 = a; len1 = s1.length();
		s2 = b; len2 = s2.length();
	}
	// trace(s1, s2, len1, len2);

	string ans = "";

	string eachs2 = "";

	for(int i=len2-1; i>=0; i--)
	{
		int carry = 0;
		eachs2 = "";
		for(int k=0; k<len2-i-1; k++)
			eachs2 += "0";

		for(int j=len1-1; j>=0; j--)
		{
			int n1 = s1[j]-'0';
			int n2 = s2[i]-'0';
			int n3 = n1*n2 + carry;
			int rem = n3%10;
			carry = n3/10;
			string t = to_string(rem);
			eachs2 += t;
		}
		if(carry > 0)
			eachs2 += char(carry+'0');
		reverse(eachs2.begin(), eachs2.end());

		ans = sum(ans, eachs2);
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string ans="1";
		for(int i=1; i<=n; i++)
			ans = multiply(ans, to_string(i));
		cout << ans << '\n';
	}
}