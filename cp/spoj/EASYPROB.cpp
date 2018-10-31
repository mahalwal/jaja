#include <bits/stdc++.h>

using namespace std;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
      cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
      const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

string dec_to_bin(int n)
{
	string ret = "";
	while(n)
	{
		if(n&1)
			ret = ret+"1";
		else 
			ret = ret+"0";
		n >>= 1;
	}
	// reverse(ret.begin(), ret.end());
	return ret;
}

int main()
{
	int arr[] = {137, 1315};//, 73, 136, 255, 1384, 16385};
	int n = 2;
	for(int j=0; j<n; j++)
	{
		string bin = dec_to_bin(arr[j]);
		trace(bin);
		int count_zero = 0;
		string ans = "";
		for(int i=bin.length()-1; i>=0; i--)
		{
			if(bin[i]=='0')
				count_zero ++;
			else if(bin[i]=='1')
			{
				if(count_zero>1)
					ans = ans+')';
				for(int k=0; k<count_zero; k++)
				{
					if(k==1)
						ans = ans + "2";
					else
						ans = ans + ")" + to_string(k) + "2(";
					if(k!=(count_zero-1))
						ans = ans + "+";
				}
				if(count_zero>1)
					ans = ans+"(2";
				if(count_zero==0)
					ans = ans + ")0(2+";
				count_zero = 0;
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
}