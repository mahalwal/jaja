#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
      cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
      const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif



int main()
{

	string s;
	cin >> s;
	while(s!="0")
	{
		int len = s.length();
		int dp[len+1];

		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		dp[1] = 1;
		if(s[1]=='0')
			dp[1] = dp[0];
		int num = (s[0]-'0')*10 + (s[1]-'0');
		if(num>=10 and num<=26)
			dp[1] = 2;
		if(s[1]=='0')
			dp[1] = 1;

		for(int i=2; i<len; i++)
		{
			num = (s[i-1]-'0')*10 + (s[i]-'0');
			if(s[i] - '0')
				dp[i] = dp[i-1];
			if(num >=10 and num<=26)
			{
				dp[i] = dp[i-2] + dp[i];
			}
		}
		// trace(dp[1]);
		cout << dp[len-1] << '\n';
		cin >> s;
	}
}