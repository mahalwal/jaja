#include <bits/stdc++.h>

using namespace std;


class myQueue {
public:
	stack<int> st;

	void push(int x)
	{
		st.push(x);
	}
	void pop()
	{
		if(st.size()==0)
			return;
		if(st.size()==1)
		{
			cout << "Popped : " <<st.top() << '\n';
			st.pop();
			return;
		}
		int t = st.top();
		st.pop();
		pop();
		st.push(t);
	}
	int peek()
	{
		return st.top();
	}
};

int main()
{

	myQueue qu;
	for(int i=1; i<=5; i++)
		qu.push(i);
	qu.pop();
	cout << "\n\n";
	while(qu.st.size()!=0)
	{
		cout << qu.peek() << '\n';
		qu.pop();
	}
}