#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n = 6;
	int arr[] = {2, 4, 7, 9, 2, 4};
	int xor_val = arr[0];

	for (int i=1; i<n; i++)
		xor_val = xor_val xor arr[i];

	int right_most_set_bit = xor_val & (-xor_val);

	int a = 0;
	int b = 0;
	for(int i=0; i<n; i++)
	{
		if(arr[i] & right_most_set_bit)
			a = a ^ arr[i];
		else
			b = b ^ arr[i];
	}
	cout << "Numbers are " << a << ' ' << b << '\n'; 
}