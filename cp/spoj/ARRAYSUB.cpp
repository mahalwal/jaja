#include<bits/stdc++.h>

using namespace std;
int main()
{
	int n, k;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	cin >> k;

	int curr_max = -1;
	int count_max = 0;
	int lptr = 0, rptr = k-1;
	for(int i=0; i<=rptr; i++)
	{
		if(arr[i]>curr_max)
		{
			count_max=1;
			curr_max = arr[i];
		}
		else if(arr[i]==curr_max)
			count_max++;
	}
	cout << curr_max << ' ';
	while(rptr<n-1)
	{
		lptr++;
		rptr++;
		if(arr[lptr-1]==curr_max)
			count_max--;
		if(arr[rptr]>curr_max)
		{
			curr_max = arr[rptr];
			count_max = 1;
		}
		else if(arr[rptr]==curr_max)
			count_max++;
		
		if(count_max==0)
		{
			curr_max = -1;
			for(int i=lptr; i<=rptr; i++)
			{
				if(arr[i]>curr_max)
				{
					curr_max = arr[i];
					count_max=1;
				}
				else if(arr[i]==curr_max)
					count_max++;
			}
		}
		cout << curr_max << " ";
	}	
	cout << '\n';
}
