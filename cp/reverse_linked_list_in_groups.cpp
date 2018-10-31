#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node* next;
}*head;


void insert(int val)
{
	if(head==NULL)
	{
		head->data = val;
		head->next = NULL;
		return;
	}
	struct node* temp = head;

	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = new node;
	temp->next->data = val;
	temp->next->next = NULL;
}

void print()
{
	struct node* temp = head;
	while(temp!=NULL)
	{
		cout << temp->data << '\n';
		temp = temp->next;
	}
}

node* reverse(node *head, int k)
{
	node* prev = NULL;
	node* cur = head;
	node* next = NULL;

	int i=0;
	while(cur and i<k)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		i++;
	}
	if(next)
		head->next = reverse(next, k);
	return prev;
}

int main()
{
	head = new node;
	head->data = 1;
	head->next = NULL;
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
	insert(8);
	print();
	head = reverse(head, 3);
	print();
}