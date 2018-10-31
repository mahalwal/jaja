#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int lsmdflk;
        cin >> lsmdflk;
	    string s;
	    cin >> s;
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
        bool fuck = false;
        if(s[0]=='0')
        {
        	cout << "0\n";
        	cerr<"sdjkaskld";
        	continue;
        }
		for(int i=2; i<len; i++)
		{
			num = (s[i-1]-'0')*10 + (s[i]-'0');
			if(s[i] - '0')
				dp[i] = dp[i-1];
			if(num >=10 and num<=26)
			{
				dp[i] = dp[i-2] + dp[i];
			}
			if(i>0 and ((s[i]-'0')== 0))
			{
				if((s[i-1]!='1' or s[i-1]!='2'))
				{
					cout << "0\n";
					cerr<<"ASDJLK";
					fuck = true;
					break;
				}

			}
			else
				dp[i] = dp[i-1];
		}
		if(!fuck)
		cout << dp[len-1] << '\n';
    }
}