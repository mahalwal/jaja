#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	while(a!=0 or b!=0 or c!=0)
	{
		int cd1 = b-a;
		int cd2 = c-b;
		if(cd1==cd2)
			cout << "AP " << c + c - b <<'\n';
		else
			cout << "GP " << c*(c/b)<< '\n';

		cin >> a >> b >> c;
	}
}