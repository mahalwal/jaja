#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		ll rootn = (ll)sqrt(1.*n);
		ll n1=-1, n2=-1;
		bool found = false;
		for(int i=0; i<=rootn+5; i++)
		{
			ll l=i, r=rootn, mid;
			while(l<=r)
			{
				mid = (l+r)/2;
				if(i*i+mid*mid<n)
					l = mid+1;
				else if(i*i+mid*mid>n)
					r = mid-1;
				else
				{
					n1 = i;
					n2 = mid;
					found=true;
					break;
				}
				// trace(l, r, mid, rootn);
			}
			if(found)
				break;

			// trace(i, mid, rootn);
		}
		// trace(n1, n2);
		if(found)
		{
			// cout << n1 <<" "<< n2 << '\n';
			cout<<"Yes\n";
		}
		else
			cout<<"No\n";
	}
}