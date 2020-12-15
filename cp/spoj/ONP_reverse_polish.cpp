/*
Manish Mahalwal
infix to reverse polish notation:
Note: op1 can stay on top of op2 only if prio(op1) > prio(op2)
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		map<char, int> mp = {
			{'+', 1},
			{'-', 2},
			{'*', 3},
			{'/', 4},
			{'^', 5}
		};

		stack<char> st;
		string ans = "";
		for(int i=0; i<s.length(); i++)
		{
			if(s[i]>='a' and s[i]<='z')
			{
				ans = ans + s[i];
			}
			else if(s[i]==')')
			{
				while(st.size()!=0 and st.top()!='(')
				{
					ans = ans + st.top();
					st.pop();
				}
				st.pop();
			}
			else if(s[i]=='(')
				st.push(s[i]);
			else
			{
				if(st.size()==0)
				{
					st.push(s[i]);
					continue;
				}
				char curr_top = st.top();
				if(mp[curr_top] < mp[s[i]])
				{
					st.push(s[i]);
				}
				else
				{
					while(mp[curr_top] >= mp[s[i]])
					{
						ans = ans + st.top();
						st.pop();
						if(st.size()==0)
							break;
						curr_top = st.top();
					}
					st.push(s[i]);
				}
			}
		}

		while(st.size()!=0)
		{
			ans = ans + st.top();
			st.pop();
		}
		cout << ans << '\n';
	}
}