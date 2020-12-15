#include <bits/stdc++.h>

using namespace std;
#define int long long

int area(int hist[], int n)
{
	stack<int> s;
	int max_area = 0;
	int tp;
	int area_with_top;
	int i=0;
	while(i<n)
	{
		if(s.empty() or hist[s.top()] <= hist[i])
			s.push(i++);
		else
		{
			tp = s.top();
			s.pop();
			if(s.empty())
				area_with_top = hist[tp]*i;
			else
				area_with_top = hist[tp]*(i-s.top()-1);
			max_area = max(max_area, area_with_top);

		}
	}
	while(!s.empty())
	{
		tp = s.top();
		s.pop();
		if(s.empty())
			area_with_top = hist[tp]*i;
		else
			area_with_top = hist[tp]*(i-s.top()-1);
		max_area = max(max_area, area_with_top);
	}
	return max_area;
}

signed main()
{
	int n;
	cin >> n;
	while(n!=0)
	{
		int hist[n];
		for(int i=0; i<n; i++)
			cin>>hist[i];
		cout << area(hist, n) << '\n';
		cin >> n;
	}
}