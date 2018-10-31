#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	long long a = 0, b;
	for(int i=0; i<n; i++){
		cin >> b;
		a ^= b;
	}
	cout << a << '\n';
}