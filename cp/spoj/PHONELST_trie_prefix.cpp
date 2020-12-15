/*
Manish Mahalwal

Prefix search in this problem
insert()
dfs()
*/

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5;

struct node
{
	char c;
	node* link[26];
	bool end;
	node()
	{
		c = 0;
		end = false;
		for(int i=0; i<26; i++)
			link[i] = NULL;
	}
};


void insert(node *root, string s)
{
	node *cur = root;
	for(int i = 0; i<s.length(); i++)
	{
		int tmp = s[i]-'0';
		if(cur->link[tmp]==NULL)
		{
			cur->link[tmp] = new node();
			cur->link[tmp]->c = s[i];
		}
		cur = cur->link[tmp];
	}
	cur->end = true;
}

bool possible = true;

void dfs(node *cur, int depth)
{
	for(int i=0; i<26; i++)
	{
		if(cur->link[i]!=NULL)
			dfs(cur->link[i], depth + 1);
	}

	if(cur->end)
	{
		for(int i=0; i<26; i++)
			if(cur->link[i]!=NULL)
				possible = false;
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		possible = true;
		node* root = new node();
		for(int i=0; i<n; i++)
		{
			string s;
			cin >> s;
			insert(root, s);
		}

		for(int i=0; i<26; i++)
			if(root->link[i]!=NULL)
				dfs(root->link[i], 0);

		if(possible)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}