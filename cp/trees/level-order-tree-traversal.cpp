#include <bits/stdc++.h>

using namespace std;

struct node
{
	node *left, *right;
	int data;
	node(int dt)
	{
		data = dt;
		left = NULL;
		right = NULL;
	}
};


void print_level_order_traversal(node *root)
{
	queue<node*> q;
	if(root)
		q.push(root);
	while(!q.empty())
	{
		node *temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
}

int main()
{
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	// root->left->right=  new node(5);
	// root->right->left = new node(6);
	root->right->right = new node(7);
	print_level_order_traversal(root);
}