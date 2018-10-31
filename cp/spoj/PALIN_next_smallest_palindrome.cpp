#include <bits/stdc++.h>

using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)

bool check9s(string s)
{
	for(int i=0; i<s.length(); i++)
		if(s[i]!='9')
			return false;
	return true;
}

string add1tothemiddle(string s)
{
	int len = s.length();
	int mid = len/2;
	int mid1 = -1;
	if(len%2==0)
	{
		mid1 = mid - 1;
	}

	int i = mid - 1;
	int j = mid + 1;
	if(len%2==0)
		i = mid1 - 1;
	if(s[mid]!='9')
	{
		s[mid] = s[mid] + 1;
		if(len%2==0)
			s[mid1]= s[mid1] + 1;
		int left_ptr = mid - 1;
		int right_ptr = mid + 1;
		if(len%2==0)
			left_ptr = mid1 - 1;
		while(left_ptr >=0 and right_ptr < len)
		{
			s[right_ptr++] = s[left_ptr--];
		}
		return s;
	}
	s[mid] = '0';
	if(len%2==0)
		s[mid1]= '0';
	int carry = 1;
	int rem = 0;

	while(i>=0)
	{
		int num = (s[i]-'0') + carry;
		rem = num%10;
		s[i] = rem+'0';
		carry = num/10;
		i--;
	}
	int new_left_size = mid - 1;
	if(len%2==0)
	{
		new_left_size = mid1 - 1;
	}
	int new_right_size = mid + 1;
	if(carry > 0)
	{
		new_left_size++;
		reverse(s.begin(), s.end());
		s = s + to_string(carry);
		reverse(s.begin(), s.end());
	}
	while(new_right_size < len and new_left_size >= 0)
	{
		s[new_right_size++] = s[new_left_size--];
	}
	if(len!=(int)s.length())
		s[len+1] = s[0]; 

	return s;
}

string solve(string s)
{
	int len = s.length();
	if(check9s(s))
	{
		string new9s = "1";
		for(int i=0; i<len-1; i++)
		{
			new9s = new9s + "0";
		}
		new9s = new9s + "1";
		return new9s;
	}

	int mid = len/2;
	int i = mid - 1;
	int j = mid + 1;
	
	if(len%2==0)
	{
		i = mid - 2;
	}
	if(len==1)
	{
		s[0] += 1;
		return s;
	}
	if(len==2)
	{
		if(s[0]==s[1])
		{
			s[0] += 1;
			s[1] += 1;
			return s;
		}
	}

	if((len%2==0 and s[mid-1] > s[mid]))
	{
		int new_left_size = mid - 1;
		int new_right_size = mid;
		while(new_right_size < len and new_left_size >=0)
			s[new_right_size++] = s[new_left_size--];
		return s;
	}

	while(s[i]==s[j])
	{
		i--;
		j++;
		if(i<0 and j==len)
			return add1tothemiddle(s);
	}
	if((len%2==0 and s[mid-1] > s[mid]) or s[i]>s[j])
	{
		int new_left_size = i;
		int new_right_size = j;
		if((len%2==0 and s[mid-1] > s[mid])==1)
		{
			new_left_size = mid - 1;
			new_right_size = mid;
		}
		while(new_right_size < len and new_left_size >=0)
		{
			s[new_right_size++] = s[new_left_size--];
		}
		return s;
	}
	else
	{
		if(len%2==0)
		{
			if(s[mid-1]!=s[mid])
			{
				s[mid] = s[mid-1];
				s[mid] += 1;
				s[mid-1] += 1;
				int new_left_size = mid-1;
				int new_right_size = mid;
				while(new_right_size < len and new_left_size >=0)
				{
					s[new_right_size++] = s[new_left_size--];
				}
				return s;
			}
		}
		return add1tothemiddle(s);
	}
	return s;
}

int main()
{
	fast_cin(); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		cout << solve(s) << '\n';
	}
	return 0;
}