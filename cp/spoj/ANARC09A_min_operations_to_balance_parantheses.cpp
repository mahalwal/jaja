#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int t=0;
	while(str[0]!='-')
	{
		int bra = 0, ket = 0;
		// stack<char> st;
		int pending = 0;
		for(int i=0; i<str.length(); i++)
		{
			if(str[i]=='{')
			{
				// st.push('{');
				pending++;
				bra++;
			}
			if(str[i]=='}')
			{
				if(pending!=0)
				{
					pending--;
					bra--;
				}
				else
					ket++;
			}
		}
		cout << ++t << ". ";
		cout << ceil(float(bra)/2)+ceil(float(ket)/2)<<'\n';
		cin >> str;
	}
}