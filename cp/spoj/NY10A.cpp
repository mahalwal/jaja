#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string str;
		cin >> str;
		map<string, int> mp = {
			{"TTT", 0}, {"TTH", 0}, {"THT", 0}, {"THH", 0}, {"HTT", 0}, {"HTH", 0}, {"HHT", 0}, {"HHH", 0}
		};
		for(int i=0; i<=37; i++)
		{
			string sub = str.substr(i, 3);
			mp[sub]++;
		}
		cout <<n<<" "<<mp["TTT"]<<" "<<mp["TTH"]<<" "<<mp["THT"]<<" "<<mp["THH"]<<" "<<mp["HTT"] <<" "<<mp["HTH"]<<" "<<mp["HHT"]<<" "<<mp["HHH"]<<'\n';
	}
}