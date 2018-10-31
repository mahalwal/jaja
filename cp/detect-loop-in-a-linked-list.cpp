#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node* next;
	node(int dt)
	{
		data = dt;
		next = NULL;
	}
};

	void insert(int dt, struct node* head)
	{
		struct node* temp = head;
		struct node* curr = new node(dt);
		if(temp==NULL)
		{
			head = curr;
			return;
		}
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = curr;
	}
	void print(struct node* head)
	{
		if(head==NULL)
			return;
		struct node* temp = head;
		while(temp!=NULL)
		{
			cout << temp->data << ":";
			temp = temp->next;
		}
		cout << '\n';
	}
	void removeLoop(node*, node*);
	bool detectloop(struct node* head)
	{
		node* slow = head;
		node* fast = head;
		while(slow and fast and fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if(slow==fast)
			{
				removeLoop(head, slow);
				return true;
			}
		}
		return false;
	}
	void removeLoop(node* head, node* slow)
	{

		node* init = head;
		node* temp = slow;
		while(temp!=init)
		{
			temp = temp->next;
			init = init->next;
		}
		node* temp2 = temp;

		while(temp2->next!=temp)
			temp2 = temp2->next;
		temp2->next = NULL;
	}

int main()
{
	struct node* head = new node(1);
	insert(2, head);
	insert(3, head);
	insert(4, head);
	insert(5, head);
	head->next->next->next->next->next = head;

	if(detectloop(head))
	{
		print(head);
		cout << "Found\n";
	}
	else
		print(head);
}